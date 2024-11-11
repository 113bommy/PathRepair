#!/usr/bin/env python3
class unionfind:
    def __init__(self, n):
        self.parent = [-1] * n
    def find(self, x):
        if self.parent[x] < 0:
            return x
        else:
            self.parent[x] = self.find(self.parent[x])
            return self.parent[x]
    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x != y:
            if self.parent[x] > self.parent[y]: x, y = y, x
            self.parent[x] += self.parent[y]
            self.parent[y] = x
    def issame(self, x, y):
        return self.find(x) == self.find(y)

N, M = map(int, input().split())
uf = unionfind(N + M)
for i in range(N):
    L = [int(x) - 1 for x in input().split()]
    for j in range(L[0] + 1):
        uf.unite(L[j + 1], M + i)
print(('NO', 'YES')[all(uf.issame(M, M + i) for i in range(N))])
