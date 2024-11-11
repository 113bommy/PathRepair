import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools
import time,random

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
mod2 = 998244353
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(): return [list(map(int, l.split())) for l in sys.stdin.readlines()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)
def pe(s): return print(str(s), file=sys.stderr)
def JA(a, sep): return sep.join(map(str, a))
def JAA(a, s, t): return s.join(t.join(map(str, b)) for b in a)


def main():
    k,q = LI()
    d = LI()
    aa = [LI() for _ in range(q)]

    def f(n,x,m):
        e = [c%m for c in d]
        n -= 1
        s = sum(e)
        t = s * (n//k) + sum(e[:n%k])
        xt = x + t
        z = [1 if c == 0 else 0 for c in e]
        zs = sum(z) * (n//k) + sum(z[:n%k])
        # print(xt, x, m, zs,n%k)
        return n - (xt//m - x//m) - zs

    r = [f(n,x,m) for n,x,m in aa]
    return JA(r, "\n")


print(main())



