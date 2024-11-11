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
    a = [c for c in S()]
    b = [c for c in S()]
    r = []

    if len(a) < len(b):
        r = sorted(a,reverse=True)
    else:
        a.sort()
        la = len(a)
        for i in range(la):
            k = 0
            for j in range(len(a)-1,-1,-1):
                if a[j] > b[i]:
                    continue
                if a[j] == b[i]:
                    t = a[:j] + a[j+1:]
                    if t <= b[i+1:]:
                        k = j
                        break
                    continue
                k = j
                break
            r.append(a[k])
            a = a[:k] + a[k+1:]
            if r[-1] < b[i]:
                r += sorted(a,reverse=True)
                break

    return ''.join(r)

print(main())


