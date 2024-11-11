import sys
from collections import defaultdict
n,p,w,d=map(int,sys.stdin.readline().split())
z=True
for y in range(w):
    a=p-y*d
    if a%w==0 and (a//w+y)<=n and a>=0:
        print(a//w,y,n-(a//w+y))
        z=False
        break
if z:
    print(-1)

    
