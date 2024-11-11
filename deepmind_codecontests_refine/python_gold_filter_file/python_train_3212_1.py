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

class Ruiwa():
    def __init__(self, a):
        self.H = h = len(a)
        self.W = w = len(a[0])
        self.R = r = a
        for i in range(h):
            for j in range(1,w):
                r[i][j] += r[i][j-1]

        for i in range(1,h):
            for j in range(w):
                r[i][j] += r[i-1][j]

    def search(self, x1, y1, x2, y2):
        if x1 > x2 or y1 > y2:
            return 0

        r = self.R
        rr = r[y2][x2]
        if x1 > 0 and y1 > 0:
            return rr - r[y1-1][x2] - r[y2][x1-1] + r[y1-1][x1-1]
        if x1 > 0:
            rr -= r[y2][x1-1]
        if y1 > 0:
            rr -= r[y1-1][x2]

        return rr


def main():
    n,m,q = LI()
    a = [[1 if c == '1' else 0 for c in S()] for _ in range(n)]
    b = [[0] * m for _ in range(n)]
    c = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            if a[i][j] == 0:
                continue
            if i > 0 and a[i-1][j]:
                b[i][j] += 1
            if j > 0 and a[i][j-1]:
                c[i][j] += 1
    A = Ruiwa(a)
    B = Ruiwa(b)
    C = Ruiwa(c)
    rr = []
    for i in range(q):
        y1,x1,y2,x2 = LI_()
        r = A.search(x1,y1,x2,y2) - B.search(x1,y1+1,x2,y2) - C.search(x1+1,y1,x2,y2)
        rr.append(r)

    return '\n'.join(map(str,rr))


print(main())
