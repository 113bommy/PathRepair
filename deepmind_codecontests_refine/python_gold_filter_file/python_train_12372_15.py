n = int(input())
mat = [list(map(int, input().split())) for _ in range(n)]
ans = 0
d = [[1] * n for _ in range(n)]
for i in range(n):
    for j, c2 in enumerate(row[i] for row in mat):
        for k, (c1, c3) in enumerate(zip(mat[j], mat[i])):
            if c1 > c2+c3:
                print(-1)
                exit(0)
            elif i != j and i != k and c1 == c2 + c3:
                d[j][k] = 0
for i in range(n):
    for j in range(n):
        if d[i][j]:
            ans += mat[i][j]
print(ans // 2)