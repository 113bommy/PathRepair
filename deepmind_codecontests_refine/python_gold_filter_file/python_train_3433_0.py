import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 998244353

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    rr = []
    while True:
        n = I()
        if n == 0:
            break
        a = LS()
        r = None
        for i in range(n):
            if a[i] == 'x':
                if i > 0 and a[i-1] == 'x':
                    r = 'none'
                    break
            else:
                a[i] = int(a[i])
                if i > 0 and a[i-1] != 'x':
                    if i % 2 == 0:
                        if a[i-1] <= a[i]:
                            r = 'none'
                            break
                    elif a[i-1] >= a[i]:
                        r = 'none'
                        break
        if r:
            rr.append(r)
            continue
        ma = -inf
        mi = inf
        for i in range(n):
            if a[i] != 'x':
                continue
            if i % 2 == 0:
                if i > 0:
                    mi = min(mi, a[i-1]-1)
                if i < n-1:
                    mi = min(mi, a[i+1]-1)
            else:
                ma = max(ma, a[i-1]+1)
                if i < n-1:
                    ma = max(ma, a[i+1]+1)
        if ma == mi:
            rr.append(ma)
        elif ma == -1 or mi == inf:
            rr.append('ambiguous')
        elif ma > mi:
            rr.append('none')
        else:
            rr.append('ambiguous')



    return '\n'.join(map(str, rr))


print(main())


