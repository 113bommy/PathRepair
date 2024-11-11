from math import inf as inf
from math import *
from collections import *
import sys
input=sys.stdin.readline
t=int(input())
while(t):
    t-=1
    n,x,m=map(int,input().split())
    ra=0
    maxl,maxr=float('inf'),-float('inf')
    chxl,chxr=x,x
    flag=0
    for i in range(m):
        l,r=map(int,input().split())
        if(not((chxl<=l and chxr>=r) or (chxl>=l and chxr>=r and chxl<=r) or(l>=chxl and l<=chxr) or (chxl>=l and chxr<=r))):
            continue
        else:
            chxl=min(l,r,chxl)
            chxr=max(l,r,chxr)
            maxl=min(l,r,maxl)
            maxr=max(l,r,maxr)
    if(maxl!=float('inf')):
        ra=chxr-chxl+1
    else:
        ra=1  
    print(ra)
