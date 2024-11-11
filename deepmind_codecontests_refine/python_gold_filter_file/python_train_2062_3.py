# union-findで行けそう。

n, m = map(int, input().split())
par = [-1] * (n + 1)


def find(a):
    if par[a] < 0:
        return a
    else:
        par[a] = find(par[a])
        return par[a]


def unite(a, b):
    a = find(a)
    b = find(b)
    if a == b:
        return False
    else:
        if par[a] < par[b]:
            a, b = b, a
        par[a] += par[b]
        par[b] = a
        return True


for i in range(m):
    x, y, z = map(int, input().split())
    unite(x, y)
cnt = 0
for i in range(n):
    if par[i + 1] < 0:
        cnt += 1
print(cnt)
