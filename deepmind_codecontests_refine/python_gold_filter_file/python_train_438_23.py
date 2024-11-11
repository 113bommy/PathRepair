n=int(input())
from math import *
for x in range(n):
    t=int(input())
    l=list(map(int,input().split()))
    p=[]
    for xy in range(t):
        p.append((xy+l[xy])%t)
    p=sorted(p)
    tx=True
    for yz in range(1,t):
        if (p[yz]-p[yz-1]!=1):
            print("No")
            tx=False
            break
    if (tx):
        print("Yes")
            
        
    
