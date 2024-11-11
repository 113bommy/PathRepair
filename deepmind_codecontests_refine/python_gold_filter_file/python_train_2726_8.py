def out():
    print(0)
    exit(0)

n, m = map(int, input().split())
r = list(map(int, input().split()))
c = list(map(int, input().split()))
res = [[-1] * m for _ in range(n)]
for i in range(n):
    for j in range(r[i]):
        res[i][j] = 1
    if r[i] < m:
        res[i][r[i]] = 0
for j in range(m):
    for i in range(c[j]):
        if not res[i][j]:
            out()
        res[i][j] = 1
    if c[j] < n:
        if res[c[j]][j] == 1:
            out()
        else:
            res[c[j]][j] = 0
print(2 ** sum([i.count(-1) for i in res]) % int(1E9 + 7))