import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools
# import time,random,resource

# sys.setrecursionlimit(10**6)
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
def IF(c, t, f): return t if c else f
def YES(c): return IF(c, "YES", "NO")
def Yes(c): return IF(c, "Yes", "No")


def main():
    t = 1

    rr = []
    for _ in range(t):
        s = S()

        t = []
        b = ""
        u = 0
        for c in s:
            if b != c:
                if u > 0:
                    t.append([b,min(2,u)])
                b = c
                u = 1
            else:
                u += 1

        t.append([b,min(2,u)])
        for i in range(1,len(t)):
            if t[i][1] > 1 and t[i-1][1] > 1:
                t[i][1] = 1

        r = []
        for b,u in t:
            r.append(b*u)
        rr.append(JA(r, ""))

    return JA(rr, "\n")


print(main())


