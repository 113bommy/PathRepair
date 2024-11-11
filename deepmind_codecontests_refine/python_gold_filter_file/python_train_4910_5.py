import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
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

def bs(f, mi, ma):
    mm = -1
    while ma > mi:
        mm = (ma+mi) // 2
        if f(mm):
            mi = mm + 1
        else:
            ma = mm
    if f(mm):
        return mm + 1
    return mm

def main():
    n = I()
    a = LI()
    b = LI()
    if b == list(range(1,n+1)):
        return 0

    ss = set(a)
    if 1 not in ss:
        i = b.index(1)
        bf = 1
        for j in range(i,n):
            if b[j] != j - i + 1:
                bf = 0
                break
        if bf:
            t = b[-1]
            s = ss | set()
            for j in range(n-t):
                if t+j+1 not in s:
                    bf = 0
                    break
                s.add(b[j])
            if bf:
                return n - t

    def f(i):
        s = ss | set(b[:i])
        for j in range(1,n+1):
            if j not in s:
                return True
            if i + j <= n:
                s.add(b[i+j-1])

        return False

    r = bs(f,0,n)

    return r + n


print(main())

