import sys
import math
import collections
input=sys.stdin.readline
t=int(input())
for w in range(t):
    n,c=(int(i) for i in input().split())
    a=[int(i) for i in input().split()]
    b=[int(i) for i in input().split()]
    l=[]
    reach=0
    r=[]
    s=0
    for i in range(n-1):
        c1=a[i]
        l.append(reach+max(0,math.ceil((c-s)/c1)))
        reach+=(math.ceil((b[i]-s)/c1))+1
        r.append(reach)
        s+=(max(0,math.ceil((b[i]-s)/c1)*c1))-b[i]
    l.append(reach+max(0,math.ceil((c-s)/a[n-1])))
    print(min(l))