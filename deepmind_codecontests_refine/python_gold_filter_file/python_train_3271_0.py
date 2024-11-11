n, m, k = map(int, input().split())
arrays = []
for i in range(n):
    arrays.append(list(map(int, input().split())))
print(m * (m - 1) // 2)
if k == 0:
    for i in range(1, m):
        for j in range(1, m - i + 1):
            print(j, j + 1)
else:
    for i in range(1, m):
        for j in range(m, i, -1):
            print(j, j - 1)