import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**10
mod = 10**9 + 7

class UnionFind:
    def __init__(self, size):
        self.table = [-1 for _ in range(size)]

    def find(self, x):
        if self.table[x] < 0:
            return x
        else:
            self.table[x] = self.find(self.table[x])
            return self.table[x]

    def union(self, x, y):
        s1 = self.find(x)
        s2 = self.find(y)
        if s1 != s2:
            if self.table[s1] <= self.table[s2]:
                self.table[s1] += self.table[s2]
                self.table[s2] = s1
            else:
                self.table[s2] += self.table[s1]
                self.table[s1] = s2
            return True
        return False

    def subsetall(self):
        a = []
        for i in range(len(self.table)):
            if self.table[i] < 0:
                a.append((i, -self.table[i]))
        return a

def f():
    n,m = list(map(int, input().split()))
    a = list(range(m+1))
    g = [False]*(m+1)
    uf = UnionFind(m+1)
    mi = None
    for _ in range(n):
        c = list(map(int, input().split()))
        if not mi:
            mi = c[1]
        g[c[1]] = True
        if c[0] > 1:
            for i in range(c[0]-1):
                g[c[2+i]] = True
                uf.union(c[1], c[2+i])

    t = uf.find(mi)

    for i in range(m+1):
        if not g[i]:
            continue
        if uf.find(i) != t:
            return 'NO'
    return 'YES'



print(f())
