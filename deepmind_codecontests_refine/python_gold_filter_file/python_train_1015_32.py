import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from bisect import bisect_left as bl, bisect_right as br, insort
from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
# from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var): sys.stdout.write('\n'.join(map(str, var)) + '\n')
def out(var): sys.stdout.write(str(var) + '\n')
from decimal import Decimal
# from fractions import Fraction
# sys.setrecursionlimit(100000)
mod = 998244353
INF=float('inf')


def construct_sum(segtree,a,n,func=max):
    for i in range(n):
        segtree[n + i] = a[i]
    for i in range(n - 1, 0, -1):
        segtree[i] = func(segtree[2 * i], segtree[2 * i + 1])

def update(pos, x, func=max):
    pos += n-1
    segtree[pos] = x
    while (pos>1):
        pos>>=1
        segtree[pos] = func(segtree[2 * pos], segtree[2 * pos + 1])

def get(l, r, func=max):
    l += n-1
    r += n-1
    s = 0
    while (l <= r):
        if l & 1:
            s = func(segtree[l],s)
            l+=1
        if (r+1) & 1:
            s = func(segtree[r],s)
            r-=1
        l >>= 1
        r >>= 1
    return s

n,k=mdata()
a=[int(data()) for i in range(n)]
n=max(a)+1
segtree = [0]*(2*n)
construct_sum(segtree,[0]*n,n)
ans=0
for i in a:
    a1=get(max(i-k+1,1),min(i+k+1,n))+1
    update(i+1,a1)
    ans=max(ans,a1)
out(ans)






