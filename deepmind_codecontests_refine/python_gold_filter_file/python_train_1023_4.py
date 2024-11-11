class UnionFind(object):
    def __init__(self, size):
        self.parent = [i for i in range(size)]
        self.rank = [0 for _ in range(size)]


    def find(self, x):
        if self.parent[x] == x:
            return x
        else:
            return self.find(self.parent[x])


    def unite(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return

        if self.rank[x] < self.rank[y]:
            self.parent[x] = y
        else:
            self.parent[y] = x
            if self.rank[x] == self.rank[y]:
                self.rank[x] += 1

    def same(self, x, y):
        return self.find(x) == self.find(y)
def compute_mst_kruskal(N, edges):#N = 頂点数、edges 0-indexed
    edges = sorted(edges, key = lambda x:x[2])
    UF = UnionFind(N)
    cost = 0
    for edge in edges:
        x, y, w = edge
        if not UF.same(x, y):
            UF.unite(x, y)
            cost+=w
    return cost
N = int(input())
ixy = []
for i in range(N):
    x, y = map(int, input().split())
    ixy.append((i, x, y))
xy_x = sorted(ixy, key = lambda x:x[1])
xy_y = sorted(ixy, key = lambda x:x[2])
edges = []
for i in range(N-1):
    i1, x1, y1 = xy_x[i]
    i2, x2, y2 = xy_x[i+1]
    edges.append((i1, i2, x2-x1))
    i1, x1, y1 = xy_y[i]
    i2, x2, y2 = xy_y[i+1]
    edges.append((i1, i2, y2-y1))
ans = compute_mst_kruskal(N, edges)
print(ans)
