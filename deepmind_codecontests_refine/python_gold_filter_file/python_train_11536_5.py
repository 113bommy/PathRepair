from collections import deque


class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.cnt = n

    def root(self, x):
        """頂点xの根を求める"""
        if self.parent[x] < 0:
            return x
        else:
            self.parent[x] = self.root(self.parent[x])
            return self.parent[x]

    def merge(self, x, y):
        """頂点xを含む集合と頂点y含む集合を結合する"""
        x = self.root(x)
        y = self.root(y)
        if x != y:
            if self.parent[x] > self.parent[y]:
                x, y = y, x
            self.parent[x] += self.parent[y]
            self.parent[y] = x
            self.cnt -= 1

    def is_same(self, x, y):
        """頂点xと頂点yが同じ集合に属するかどうかを返す"""
        return self.root(x) == self.root(y)

    def get_size(self, x):
        """頂点xを含む集合の要素数を返す"""
        return -self.parent[self.root(x)]

    def get_cnt(self):
        """木の個数を返す"""
        return self.cnt
      

n, m = map(int, input().split())
info = [list(map(int, input().split())) for i in range(m)]

# 辺数が奇数のときは構成不可能
if m % 2 != 0:
    print(-1)
    exit()

# 全域木の構成
uf = UnionFind(n)
tree = [[] for i in range(n)]
cnt = [0] * n
ans = []
for i in range(m):
    a, b = info[i]
    a -= 1
    b -= 1
    if uf.is_same(a, b):
        cnt[a] += 1
        ans.append((a + 1, b + 1))
    else:
        uf.merge(a, b)
        tree[a].append(b)
        tree[b].append(a)

# トポロジカルソート
root = 0
tps = [None] * n
q = deque([(-1, root)])
i = 0
while q:
    par, pos = q.pop()
    tps[i] = (par, pos)
    i += 1
    for child in tree[pos]:
        if par == child:
            continue
        else:
            q.append((pos, child))

# トポロジカル順の逆順で集めていく
for par, pos in tps[::-1]:
    if par == -1:
        continue
    if cnt[pos] % 2 == 0:
        cnt[par] += 1
        ans.append((par + 1, pos + 1))
    else:
        cnt[pos] += 1
        ans.append((pos + 1, par + 1))

# 答えの出力
for i in ans:
    print(*i)