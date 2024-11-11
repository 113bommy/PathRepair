from bisect import *
from collections import *
from fractions import gcd
from math import factorial
from itertools import *
from heapq import *



N=int(input())
LR=[list(map(int,input().split())) for i in range(N)]
for i in range(N):
    LR[i][1]+=1

value=max([R-L for L,R in LR])
#LR=sorted(LR,key=lambda x:x[1])
LR=sorted(LR,key=lambda x:x[0]*10**9+x[1])
a=2*(10**9)
minRlst=[a for i in range(N)]
minRlst[-1]=LR[-1][1]
maxLlst=[0 for i in range(N)]
maxLlst[0]=LR[0][0]
for i in range(N-2,-1,-1):
    minRlst[i]=min(minRlst[i+1],LR[i][1])
for i in range(1,N):
    maxLlst[i]=max(minRlst[i-1],LR[i][0])
L1,R1=LR[0]
L2,R2=LR[-1][0],minRlst[1]
maxR=min([R for L,R in LR])
for i in range(0,N-1):
    L,R=LR[i]
    a=max(R-L,0)
    b=max(maxR-LR[-1][0],0)
    value=max(value,a+b)
    L1=L
    R1=min(R1,R)
    R2=minRlst[i+1]
    a=max(R1-L1,0)
    b=max(R2-L2,0)
    value=max(value,a+b)
print(value)
