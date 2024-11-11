from collections import defaultdict
from heapq import heappop, heappush

class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [0] * (n)

    def find(self, x):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def same_check(self, x, y):
        return self.find(x) == self.find(y)

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if self.rank[x] < self.rank[y]:
            self.par[x] = y
        else:
            self.par[y] = x
            if self.rank[x] == self.rank[y]:
               self.rank[x] += 1

N, M = list(map(int, input().split()))
uf = UnionFind(N)

a = list(map(int, input().split()))

for i in range(M):
    x, y = list(map(int, input().split()))
    uf.union(x, y)

D = defaultdict(list)
for i in range(N):
    D[uf.find(i)].append(a[i])

for i in D:
    D[i] = sorted(D[i])

ans = 0
Q = []

x = len(D)
for i in D:
    if len(D[i]) == 1:
        ans += D[i][0]
    else:
        ans += D[i][0]
        m = len(D[i])
        for j in range(1, m):
            heappush(Q, D[i][j])

if len(D) == 1:
    print(0)
else:
    if N >= 2 * len(D) - 2:
        for i in range(len(D) - 2):
            x = heappop(Q)
            ans += x
        print(ans)
    else:
        print("Impossible")
