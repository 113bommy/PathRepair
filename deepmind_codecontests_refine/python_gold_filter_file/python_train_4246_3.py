from collections import Counter
import sys

sys.setrecursionlimit(10 ** 6)


N, M = map(int, input().split())
parent = [-1] * N


def union(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return
    parent[x] = y


def find(x):
    if parent[x] == -1:
        return x
    res = parent[x] = find(parent[x])
    return res

for _ in range(M):
    a, b = map(int, input().split())
    union(a - 1, b - 1)


count = Counter(find(i) for i in range(N))
print(count.most_common(1)[0][1])
