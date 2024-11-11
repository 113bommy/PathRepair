from bisect import *
from heapq import *
n,x,y=map(int,input().split())
a=list(map(int,input().split()))
heapify(a)
c=0
if(x>y):
    print(n)
else:
    while(1):
        if(len(a)==0):
            break
        x1=heappop(a)
        if(x1>x):
            break
        c+=1
        if(len(a)!=0):
            x1=heappop(a)
            heappush(a,x1+y)
    print(c)
