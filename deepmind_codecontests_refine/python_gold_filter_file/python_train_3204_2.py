class UnionFind:
    def __init__(self, size):
        self.par = [-1] * size
        
    def find(self, x):
        if self.par[x] < 0:
            return x
        else:
            self.par[x] = self.find(self.par[x])
            return self.par[x]

    def unite(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y: return False
        if self.par[x] > self.par[y]:
            x, y = y, x
        self.par[x] += self.par[y]
        self.par[y] = x
        return True

    def same(self, x, y):
        return self.find(x) == self.find(y)
    
    def size(self, x):
        return -self.par[self.find(x)]

N, Q = map(int, input().split())
uf = UnionFind(N)
for _ in range(Q):
    t, u, v = map(int, input().split())
    if t == 0:
        uf.unite(u, v)
    else:
        if uf.same(u, v):
            print(1)
        else:
            print(0)