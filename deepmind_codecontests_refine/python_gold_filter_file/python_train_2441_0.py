n, m, k = [int(i) for i in input().split()]
cur = 0
colored = 0
a = [[0] * m for i in range(n)]
res = [[] for i in range(k)]
for i in range(0, n - 1, 2):
    for j in range(m):
        if colored == 2:
            cur = min(cur + 1, k - 1)
            colored = 0
        res[cur].append(i)
        res[cur].append(j)
        colored += 1
    for j in range(m - 1, -1, -1):
        if colored == 2:
            colored = 0
            cur = min(cur + 1, k - 1)
        res[cur].append(i + 1)
        res[cur].append(j)
        colored += 1
if n % 2 == 1:
    for j in range(m):
        if colored == 2:
            colored = 0
            cur = min(cur + 1, k - 1)
        res[cur].append(n - 1)
        res[cur].append(j)
        colored += 1

for i in res:
    print(len(i) // 2, end=" ")
    print(" ".join([str(j + 1) for j in i]))