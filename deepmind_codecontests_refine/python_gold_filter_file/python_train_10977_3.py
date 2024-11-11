m, n = map(int, input().split())
res = m
for i in range(1, m):
    res -= (i / m) ** n
print(res)