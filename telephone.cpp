/*
Consider telephone book database of N clients. 
Make use of a hash table implementation to quickly look up client�s telephone number.
*/ 
    #include<iostream>
    #include<cstdlib>
    #include<string>
    #include<cstdio>
    using namespace std;
    const int TABLE_SIZE = 20;

    class HashEntry
    {
        public:
            int key;
            int value;
            HashEntry(int key, int value)//parameteized constructor
            {
                this->key = key;
                this->value = value;
            }
    };//end of class

    class HashMap

    {
        private:
            HashEntry **table;
        public:
            HashMap()
     {
                table = new HashEntry * [TABLE_SIZE];
                for (int i = 0; i< TABLE_SIZE; i++)
                {
                    table[i] = NULL;
                }
            }
            int HashFunc(int key)//division hash function
            {
                return key % TABLE_SIZE;
            }
     void Insert(int key, int value)//insert operation
     {
                int hash = HashFunc(key);
                while (table[hash] != NULL && table[hash]->key != key)
                {
                    hash = HashFunc(hash + 1);
                }
                if (table[hash] != NULL)

                    delete table[hash];
                table[hash] = new HashEntry(key, value);
     }
            int Search(int key)//search operation
     {
         int  hash = HashFunc(key);
         while (table[hash] != NULL && table[hash]->key != key)
         {
             hash = HashFunc(hash + 1);
         }
         if (table[hash] == NULL)
             return -1;
         else
             return table[hash]->value;
            }

            void Remove(int key)
     {
         int hash = HashFunc(key);
         while (table[hash] != NULL)
         {
             if (table[hash]->key == key)
                 break;

             hash = HashFunc(hash + 1);
         }
                if (table[hash] == NULL)
         {
                    cout<<"No Element found at key "<<key<<endl;
                    return;
                }
                else
                {
                    delete table[hash];
                }
                cout<<"Element Deleted"<<endl;
            }
            ~HashMap()//destructor
     {
                for (int i = 0; i < TABLE_SIZE; i++)
                {
                    if (table[i] != NULL)
                        delete table[i];
                    delete[] table;
                }
            }
    };

    int main()//program execution starts from here
    {
        HashMap hash;
        int key, value;
        int choice;
        while (1)
        {
            cout<<"\n----------------------"<<endl;
            cout<<"Operations on Hash Table"<<endl;
            cout<<"\n----------------------"<<endl;
            cout<<"1.Insert element into the table"<<endl;
            cout<<"2.Search element from the key"<<endl;
            cout<<"3.Delete element at a key"<<endl;
            cout<<"4.Exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"Enter element to be inserted: ";
                cin>>value;
                cout<<"Enter key at which element to be inserted: ";
                cin>>key;
                hash.Insert(key, value);
                break;

            case 2:
                cout<<"Enter key of the element to be searched: ";
                cin>>key;
                if (hash.Search(key) == -1)
                {
             cout<<"No element found at key "<<key<<endl;
             continue;
         }
         else
         {
             cout<<"Element at key "<<key<<" : ";
             cout<<hash.Search(key)<<endl;
         }
                break;
            case 3:
                cout<<"Enter key of the element to be deleted: ";
                cin>>key;
                hash.Remove(key);
                break;
            case 4:
                exit(1);
            default:
               cout<<"\nEnter correct option\n";
           }
        }
        return 0;
    }
	
/*output:
----------------------
Operations on Hash Table

----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 1
Enter element to be inserted: 3
Enter key at which element to be inserted: 1

----------------------
Operations on Hash Table

----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 1
Enter element to be inserted: 4
Enter key at which element to be inserted: 2

----------------------
Operations on Hash Table

----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 2
Enter key of the element to be searched: 2
Element at key 2 : 4

----------------------
Operations on Hash Table

----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 3
Enter key of the element to be deleted: 2
Element Deleted

----------------------
Operations on Hash Table

----------------------
1.Insert element into the table
2.Search element from the key
3.Delete element at a key
4.Exit
Enter your choice: 4
*/
