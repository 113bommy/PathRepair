# AtCoder Regular Contest 065
# D - 連結 / Connectivity
# https://atcoder.jp/contests/arc065/tasks/arc065_b
import sys
from collections import defaultdict

class UnionFind:
    def __init__(self, n):
        self.parent = [i for i in range(n)]
    def find(self, x):
        if self.parent[x] == x:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return
        self.parent[x] = y

def main():
    N, *KL = map(int, input().split())
    uf = [UnionFind(N) for _ in range(2)]
    for i in range(2):
        for j in range(KL[i]):
            p, q = map(int, input().split())
            uf[i].union(p-1, q-1)

    d = defaultdict(int)
    for i in range(N):
        d[(uf[0].find(i), uf[1].find(i))] += 1

    for i in range(N):
        print(d[(uf[0].find(i), uf[1].find(i))], end = " ")
    print("")

if __name__ == "__main__":
    sys.setrecursionlimit(10**6)
    main()
