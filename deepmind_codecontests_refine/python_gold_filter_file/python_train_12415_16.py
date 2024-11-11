#######################################################################################################################
#   Author:     BlackFyre
#   Language:   PyPy 3.7
#######################################################################################################################
 
from sys import stdin, stdout, setrecursionlimit
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log, log2
from random import seed, randint
from datetime import datetime
from collections import defaultdict as dd, deque
from heapq import merge, heapify, heappop, heappush, nsmallest
from bisect import bisect_left as bl, bisect_right as br, bisect
from collections import defaultdict as dd
mod = pow(10, 9) + 7
mod2 = 998244353
# setrecursionlimit(3000)

def inp(): return stdin.readline().strip()
def iinp(): return int(inp())
def out(var, end="\n"): stdout.write(str(var) + "\n")
def outa(*var, end="\n"): stdout.write(' '.join(map(str, var)) + end)
def lmp(): return list(mp())
def mp(): return map(int, inp().split())
def smp(): return map(str, inp().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(m, val) for j in range(n)]
def remadd(x, y): return 1 if x % y else 0
def ceil(a, b): return (a + b - 1) // b
def def_value(): return 0
def def_inf(): return inf

def mex(a,n):
    x = set(a)
    for i in range(n+1):
        if i not in x:
            return i

for _ in range(iinp()):
    n = iinp()
    a = lmp()
    ans = []
    while a!=sorted(a):
        x = mex(a,n)
        if x==n:
            for i in range(n):
                if a[i]!=i:
                    a[i]=x
                    ans.append(i+1)
                    break
        else:
            a[x]=x
            ans.append(x+1)
    print(len(ans))
    print(*ans)