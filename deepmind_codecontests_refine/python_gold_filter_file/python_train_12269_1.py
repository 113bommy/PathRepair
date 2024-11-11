import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools
 
sys.setrecursionlimit(10**7)
inf = 10**20
mod = 10**9 + 7
 
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
 
def main():
    n = I()
    a = sorted([sorted(LI()) + [_] for _ in range(n)])
    b = sorted(a, key=lambda x: x[1])
    r = (a[-1][0]-a[0][0]) * (b[-1][1]-b[0][1])
 
 
    bm = b[-1][1] - a[0][0]
    bmi = b[0][2]
    am = a[-1][1]
    at = 0
    k = [[inf,0]]
    for i in range(n-1):
        kk = []
        kk.append(min(k[-1][0], b[i][0], b[i+1][1]))
        kk.append(max(k[-1][1], b[i][0]))
        if kk[0] == k[-1][0]:
            k[-1][1] = kk[1]
        else:
            k.append(kk)
 
    k = k[1:]
    kl = len(k)
 
    am = b[-1][1] - a[0][0]
    ami = a[0][2]
    bm = 0
    mtm = 0
    bt = b[0][1]
 
    for i in range(n-1,0,-1):
        tm = b[i][0]
        if mtm < tm:
            mtm = tm
        if ami == b[i][2]:
            break
        if tm < bt:
            bt = tm
        if tm < b[i-1][1]:
            tm = b[i-1][1]
        bm = mtm
        if tm > bm:
            bm = tm
 
        tr = am * (bm-bt)
        if r > tr:
            r = tr
 
        for j in range(kl):
            ki,km = k[j]
            if km > bm:
                break
            tr = am * (bm-min(ki,bt))
            if r > tr:
                r = tr
 
    return r
 
 
print(main())