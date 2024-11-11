import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
# from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var): sys.stdout.write(' '.join(map(str, var)) + '\n')
def out(var): sys.stdout.write(str(var) + '\n')
from decimal import Decimal
# from fractions import Fraction
# sys.setrecursionlimit(100000)
mod = int(1e9) + 7
INF=10**8

n,m=mdata()
if n==1 and m==0:
    out(1)
    exit()
l=[]
k=math.floor(((1+4*m)**0.5-1)/2)
if k>n:
    out(-1)
    exit()
l=list(range(1,2*k+3))
m-=k*(k+1)
while m:
    l.append(l[-1]+l[max(0,l[-1]-2*m)])
    m-=min(m,l[-1]//2)
if len(l)>n:
    out(-1)
    exit()
i=0
t=l[-1]
while len(l)<n:
    l.append(INF+i*(t+1))
    i+=1
outl(l)
