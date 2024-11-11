N, M = map(int, input().split())

parent = [i for i in range(N + M)]
rank = [0] * (N + M)


def find(i):
    if parent[i] == i:
        return i
    else:
        parent[i] = find(parent[i])
        return parent[i]


def same(x, y):
    return find(x) == find(y)


def unite(x, y):
    x = find(x)
    y = find(y)
    if x == y:
        return

    if rank[x] > rank[y]:
        parent[y] = x
    else:
        parent[x] = y
        if rank[x] == rank[y]:
            rank[y] += 1


for i in range(N):
    P = list(map(int, input().split()))
    n = P[0]
    for j in range(1, n + 1):
        unite(i, P[j] - 1 + N)


k = find(0)
for i in range(N):
    if k != find(i):
        print('NO')
        exit()

print('YES')