a = input().split(" ")
n = int(a[0])
m = int(a[1])
F = [["."] * (m) for i in range(n)]
for i in range(n):
    for j in range(m):
        if (i % 2 == 0) or ((i % 4 == 1) and (j == m - 1)) or ((i % 4 == 3) and (j == 0)):
            F[i][j] = '#'
for row in F:
    print(''.join(row))