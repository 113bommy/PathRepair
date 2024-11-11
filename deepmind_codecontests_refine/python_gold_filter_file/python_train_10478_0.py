import sys,math,itertools
from collections import Counter,deque,defaultdict
from bisect import bisect_left,bisect_right 
from heapq import heappop,heappush,heapify, nlargest
from copy import deepcopy
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))
def inpl_1(): return list(map(lambda x:int(x)-1, sys.stdin.readline().split()))
def inps(): return sys.stdin.readline()
def inpsl(x): tmp = sys.stdin.readline(); return list(tmp[:x])
def err(x): print(x); exit()

n = inp()
a = inpl(); a.sort()
c = Counter(a)
now = a[0]
mx = max(a)
A = 0
nn = 1
for i in range(1,n+1):
    nn *= i; nn %= mod
res = 0
for i,x in enumerate(a):
    if now != x:
        A += c[now]
        now = x
    if mx == x: break
    # print(x,A)
    tmp = nn*x*pow(n-A,mod-2,mod)%mod
    tmp %= mod
    res += tmp
    res %= mod
print(res)