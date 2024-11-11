from heapq import heappop
from collections import defaultdict

class UnionFind:
    def __init__(self, size):
        self.data = [-1] * size
    def find(self, x):
        if self.data[x] < 0:
            return x
        else:
            self.data[x] = self.find(self.data[x])
            return self.data[x]
    def union(self, x, y):
        x, y = self.find(x), self.find(y)
        if x != y:
            if self.data[y] < self.data[x]:
                x, y = y, x
            self.data[x] += self.data[y]
            self.data[y] = x
        return (x != y)
    def same(self, x, y):
        return (self.find(x) == self.find(y))
    def size(self, x):
        return -self.data[self.find(x)]


N, M, *L = map(int, open(0).read().split())
A, XY = L[:N], L[N:]

uf = UnionFind(N)
for x, y in zip(*[iter(XY)] * 2):
    uf.union(x, y)

C = defaultdict(list)
for i, a in enumerate(A):
    C[uf.find(i)].append(a)

if len(C) < 2:
    print(0)
    quit()

D = [sorted(c) for c in C.values()]
s = sum(heappop(d) for d in D)

L = []
for d in D:
    L += d

if len(L) < len(D) - 2:
    print("Impossible")
else:
    print(s + sum(sorted(L)[:len(D) - 2]))
