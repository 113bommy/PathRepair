import math
for i in range(1):
    n=int(input())
    l=list(map(int,input().split()))
    ans=0
    for i in range(n):
        c=0
        for j in range(i,n):
            c=c^l[j]
            ans=max(ans,c) 
    print(ans)    
            
            
            
            
        
        

            
    