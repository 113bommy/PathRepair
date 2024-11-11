from sys import stdin
import math
t=int(stdin.readline())
while t:
    a,b,c,d,k=map(int,stdin.readline().split())
    x,y=math.ceil(a/c),math.ceil(b/d)
    if (x+y)<=k:
        print(x,y)
    else:
        print(-1)
    t-=1
