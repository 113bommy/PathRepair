n,k=input ().split (); k = int (k); n=n [::-1]; 
for i in range (0,100) : 
    if n [:i].count ("0")>=k : 
        print (i-k); 
        break;
else : print (str (len (n)-1))