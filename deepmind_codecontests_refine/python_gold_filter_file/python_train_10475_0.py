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


def main():
    n = I()
    t = [[S(), [set() for _ in range(151)]] for _ in range(n)]
    m = I()
    q = [LI_() for _ in range(m)]
    for c in t:
        s = c[0]
        l = len(s)
        for i in range(1,min(151,l+1)):
            for j in range(l-i+1):
                c[1][i].add(s[j:j+i])

    rr = []
    for li,ri in q:
        l = t[li]
        r = t[ri]
        c = ['',[l[1][i]|r[1][i] for i in range(151)]]
        for i in range(1,min(150,len(l[0])+1)):
            ls = l[0][-i:]
            for j in range(1,min(151-i,len(r[0])+1)):
                c[1][i+j].add(ls+r[0][:j])

        c[0] = l[0] + r[0]
        if len(c[0]) > 300:
            c[0] = c[0][:150] + c[0][-150:]
        t.append(c)
        r = 0
        for i in range(1,151):
            tt = len(c[1][i])
            if tt != 2**i:
                break
            r = i
        rr.append(r)


    return '\n'.join(map(str,rr))


print(main())


