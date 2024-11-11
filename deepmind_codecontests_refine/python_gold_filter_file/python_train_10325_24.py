import math
import bisect
import copy
from collections import defaultdict
from collections import OrderedDict
#for _ in range(int(input())):
n = int(input())
#s = list(input())
#n = len(s)
#print(s)

#n,m = map(int,input().split())


ar = list(map(int,input().split()))
p = max(ar)


if sum(ar) %2 == 0 and sum(ar)-p >= p:
    print('YES')
       
else:
    print('NO')
    


        

        
        
        



    

    
        


    
    
            
                

                

        

        

                
                
            
            
            
    

    

    


    
    


"""
stuff you should look for
    * int overflow, array bounds
    * special cases (n=1?)
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
"""
    
