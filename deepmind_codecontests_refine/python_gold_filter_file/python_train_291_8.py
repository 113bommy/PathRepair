import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**15
mod = 10**9+7

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    n,m = LI()
    e = [[] for _ in range(n)]
    if m > 0:
        for _ in range(m):
            l,r,d = LI()
            e[l-1].append((r-1,d))
            e[r-1].append((l-1,-d))

    b = [None] * n

    for i in range(n):
        if not b[i] is None:
            continue
        b[i] = 0
        q = [i]
        qi = 0
        nq = []
        while True:
            if len(q) == qi:
                if not nq:
                    break
                q = nq
                qi = 0
                nq = []
            j = q[qi]
            qi += 1
            c = b[j]
            for r,d in e[j]:
                if b[r] is None:
                    b[r] = c+d
                    nq.append(r)
                else:
                    if b[r] != c+d:
                        return 'No'

    return 'Yes'


print(main())


