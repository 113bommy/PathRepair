from collections import defaultdict


class UnionFind3:
    def __init__(self, size):
        self.table = [-1 for _ in range(size)]

    def find(self, x):
        while self.table[x] >= 0:
            x = self.table[x]
        return x

    def root(self, x):
        if self.table[x] < 0:
            return x
        else:
            self.table[x] = self.root(self.table[x])
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


n, k, l = map(int, input().split())
ufd, ufr = UnionFind3(n), UnionFind3(n)
for _ in range(k):
    p, q = map(int, input().split())
    ufd.union(p - 1, q - 1)
for _ in range(l):
    r, s = map(int, input().split())
    ufr.union(r - 1, s - 1)
d = defaultdict(int)
for i in range(n):
    d[ufd.root(i), ufr.root(i)] += 1
print(*(d[ufd.root(i), ufr.root(i)] for i in range(n)))
