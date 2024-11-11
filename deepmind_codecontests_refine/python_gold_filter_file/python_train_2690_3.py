H, W = map(int, input().split())
c = [list(map(int, input().split())) for i in range(10)]
A = [list(map(int, input().split())) for i in range(H)]

for k in range(10):
    for i in range(10):
        for j in range(10):
            c[i][j] = min(c[i][j], c[i][k]+c[k][j])

ans = 0
for row in A:
    for a in row:
        if a < 0:
            continue
        ans += c[a][1]
print(ans)