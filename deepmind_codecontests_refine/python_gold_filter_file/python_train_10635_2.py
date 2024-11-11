class UnionFind:
    def __init__(self, n):
        self.par = [i for i in range(n)]
        self.rank = [1] * (n + 1)
        self.rank[0] = 0

    def union(self, x, y):
        if not self.same_set(x, y):
            par_x = self.find(x)
            par_y = self.find(y)

            if self.rank[par_x] >= self.rank[par_y]:
                self.rank[par_x] += self.rank[par_y]
                self.rank[par_y] = 0
                self.par[par_y] = par_x
            else:
                self.rank[par_y] += self.rank[par_x]
                self.rank[par_x] = 0
                self.par[par_x] = par_y
            self.find(x)
            self.find(y)

    def find(self, x):
        if self.par[x] == x: return x
        self.par[x] = self.find(self.par[x])
        return self.par[x]

    def same_set(self, x, y):
        return self.find(x) == self.find(y)

n, m = map(int, input().split())

adj = [[] for i in range(n + 1)]

arestas = []

for i in range(m):
    a, b = map(int, input().split())

    adj[a].append(b)
    adj[b].append(a)

    arestas.append((a, b))

maior = 1

for i in range(1, n + 1):
    if len(adj[i]) > len(adj[maior]): maior = i

ans = []
uf = UnionFind(n+1)

for v in adj[maior]:
    ans.append((maior, v))
    uf.union(maior, v)

for a, b in arestas:
    if a == maior or b == maior: continue

    if not uf.same_set(a, b):
        ans.append((a, b))
        uf.union(a, b)

for a, b in ans:
    print(a, b)
