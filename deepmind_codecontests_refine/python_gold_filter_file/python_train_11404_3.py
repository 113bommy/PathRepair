n, t = map(int, input().split())
fill = 0
k = [[0] * (i + 1) for i in range(n + 1)]
k[0][0] = t
for i in range(n):
    for j in range(i + 1):
        if k[i][j] >= 1:
            fill += 1
            k[i +1][j] += (k[i][j] -1) / 2
            k[i + 1][j + 1] += (k[i][j] -1) / 2
print(fill)
