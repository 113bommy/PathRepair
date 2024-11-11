import sys


class UnionFind():
    def __init__(self, n):
        self.n = n
        self.p = [i for i in range(n + 5)]
        self.rank = [0 for i in range(n + 5)]

    def find_set(self, x):
        if self.p[x] != x:
            self.p[x] = self.find_set(self.p[x])
        return self.p[x]

    def unite(self, x, y):
        px, py = self.find_set(x), self.find_set(y)
        if px == py:
            return
        if self.rank[px] > self.rank[py]:
            self.p[py] = px
        else:
            self.p[px] = py
            if self.rank[px] == self.rank[py]:
                self.rank[py] += 1


def main():
    sys.setrecursionlimit(int(1e5))
    nvertices, nedges = map(int, input().split())
    E = []
    uf = UnionFind(nvertices)
    for i in range(nedges):
        s, t, w = map(int, input().split())
        E.append((w, s, t))
    E.sort()

    ans = 0
    for w, s, t in E:
        if uf.find_set(s) != uf.find_set(t):
            ans += w
            uf.unite(s, t)

    print(ans)


main()