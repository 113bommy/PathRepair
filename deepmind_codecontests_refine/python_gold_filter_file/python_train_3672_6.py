import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
#from fractions import Fraction
#sys.setrecursionlimit(100000)
INF = float('inf')
mod=10**9+7


n=int(data())
h=mdata()
stack1=[h[0]]
stack2=[h[0]]
d=dd(int)
for i in range(1,n):
    k=INF
    while stack1 and stack1[-1]>h[i]:
        if stack1[-1]<h[i-1]:
            k=min(k,d[stack1[-1]])
        stack1.pop()
    while stack2 and stack2[-1]<h[i]:
        if stack2[-1]>h[i-1]:
            k = min(k, d[stack2[-1]])
        stack2.pop()
    if stack1:
        k=min(k,d[stack1[-1]])
    if stack2:
        k = min(k, d[stack2[-1]])
    d[h[i]]=k+1
    stack1.append(h[i])
    stack2.append(h[i])
out(d[h[-1]])
