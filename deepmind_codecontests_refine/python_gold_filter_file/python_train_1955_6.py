#import sys
#import numpy as np
import math
#from fractions import Fraction
import itertools
from collections import deque
from collections import Counter
import heapq
from fractions  import gcd
#input=sys.stdin.readline
#import bisect

n=int(input())
d={}
res=[[0,0] for _ in range(n)]
for i in range(n):
    a=float(input())
    b=round(a*pow(10,9))
    x=0
    y=0
    f=True
    while f:
        f=False
        if b%2==0:
            x+=1
            b=b//2
            f=True
        if b%5==0:
            y+=1
            b=b//5
            f=True
    if x*100+y not in d:
        d[x*100+y]=1
    else:
        d[x*100+y]+=1
    res[i]=[x,y]
ans=0
for i in range(n):
    x,y=res[i]
    for j in d:
        xc=j//100
        yc=j%100
        if xc+x>=18 and yc+y>=18:
            if xc==x and yc==y:
              ans+=d[j]-1
            else:
              ans+=d[j]
print(ans//2)
