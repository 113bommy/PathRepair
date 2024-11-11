import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(-1,0),(0,1),(1,0),(0,-1)]
ddn = [(-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1)]

def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(): return [tuple(map(int, l.split())) for l in sys.stdin]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n,m = LI()
    if n == 1:
        return 1
    e = collections.defaultdict(list)
    for _ in range(n-1):
        a,b = LI_()
        e[a].append(b)
        e[b].append(a)

    w = [None] * n

    d = [None] * n
    def f(i,p):
        r = 1
        s = [1]
        t = []
        for c in e[i]:
            if c == p:
                s.append(r)
                t.append(1)
                continue
            u = f(c,i) + 1
            r *= u
            r %= m
            s.append(r)
            t.append(u)
        for j in range(len(t)-2, -1, -1):
            t[j] *= t[j+1]
            t[j] %= m
        t.append(1)
        d[i] = [s, t]
        w[i] = r
        return r

    def g(i,p,k):
        w[i] *= k
        w[i] %= m
        s,t = d[i]
        for j,c in enumerate(e[i]):
            if c == p:
                continue
            g(c,i,(s[j] * t[j+1] * k) % m + 1)

    f(0, -1)
    g(0, -1, 1)
    return '\n'.join(map(str, w))


print(main())
