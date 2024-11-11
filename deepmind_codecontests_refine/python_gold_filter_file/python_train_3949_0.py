import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time,copy,functools

sys.setrecursionlimit(10**7)
inf = 10**20
eps = 1.0 / 10**10
mod = 10**9+7
dd = [(0,-1),(1,0),(0,1),(-1,0)]
ddn = [(0,-1),(1,-1),(1,0),(1,1),(0,1),(-1,-1),(-1,0),(-1,1)]

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
        n,M,A,B,C,T = LI()
        if n == 0:
            break
        a = tuple(LI())
        if T == 0:
            rr.append(' '.join(map(str, a)))
            continue
        m = [[0]*n for _ in range(n)]
        for i in range(n):
            m[i][i] = B
            if i > 0:
                m[i][i-1] = A
            if i < n-1:
                m[i][i+1] = C
        mod = M

        class Matrix():
            def __init__(self, A):
                self.A = A
                self.row = len(A)
                self.col = len(A[0])

            def __iter__(self):
                return self.A.__iter__()

            def __getitem__(self, i):
                return self.A.__getitem__(i)

            def __add__(self, B):
                aa = self.A
                bb = B.A
                return Matrix([[(aa[i][j] + bb[i][j]) for j in range(self.col)] for i in range(self.row)])

            def __sub__(self, B):
                aa = self.A
                bb = B.A
                return Matrix([[aa[i][j] - bb[i][j] for j in range(self.col)] for i in range(self.row)])

            def __mul__(self, B):
                bb = [[B.A[j][i] for j in range(B.row)] for i in range(B.col)]
                return Matrix([[sum([ak * bk for ak,bk in zip(ai,bj)]) % mod for bj in bb] for ai in self.A])

            def __truediv__(self, x):
                pass

            def pow(self, n):
                A = self
                r = Matrix([[0 if j != i else 1 for j in range(self.row)] for i in range(self.row)])
                while n > 0:
                    if n % 2 == 1:
                        r *= A
                    A *= A
                    n //= 2
                return r

            def __str__(self):
                return self.A.__str__()


        m = Matrix(m)
        mp = m.pow(T)
        r = mp * Matrix([[a[i]] for i in range(n)])
        rr.append(' '.join(map(lambda x: str(x[0]), r)))

    return '\n'.join(map(str,rr))


print(main())


