import math
m,n=map(int,input().split())
k=1
for i in range(m):
    if i%2 == 0:
        for j in range(n-1):
            print("#",end="")
        print("#")
    else:
        if k ==1:
            for j in range(n-1):
                print(".",end="")
            print("#")
            k*=-1
        else:
            print("#",end="")
            for j in range(1,n-1):
                print(".",end="")
            print(".")
            k*=-1
            
        
            
    
    

