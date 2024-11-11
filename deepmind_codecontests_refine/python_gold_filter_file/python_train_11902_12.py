
import math

def solve():
 
    
    n,x,t=map(int,input().split())
    ##3x,y=map(int,input().split())
    #a,b=map(int,input().split())
    #n=int(input())
    #l=list(map(int,input().split()))
    v=min(n-1,t//x)
    if(v==0):
        print(0)
    else:
        s=max(0,v*(v-1)//2)+v*(n-v)
        print(s)
    
            
    
    

    



t=int(input())
for z in range(t):
    solve()
    