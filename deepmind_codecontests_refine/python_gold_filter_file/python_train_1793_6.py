import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
#from bisect import bisect_left as bl, bisect_right as br, insort
#from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.buffer.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
#from fractions import Fraction
#sys.setrecursionlimit(100000)
#INF = float('inf')
mod = int(1e9)+7

def cal(x):
    l1=set()
    d=dd(int)
    a=[]
    for i in range(n):
        k=0
        for j in range(m):
            if A[i][j]>=x:
                k+=1<<j
        l1.add(k)
        d[k]=i+1
    l1=list(l1)
    s=(1<<m)-1
    for i in l1:
        for j in l1:
            if i|j == s:
                a=[d[i],d[j]]
    return a

n,m=mdata()
A=[mdata() for i in range(n)]
l,r=0,10**9
while l<=r:
    mid=(l+r)//2
    if cal(mid):
        l=mid+1
    else:
        r=mid-1
a=cal(mid)
if a:
    outl(a)
else:
    outl(cal(mid-1))




