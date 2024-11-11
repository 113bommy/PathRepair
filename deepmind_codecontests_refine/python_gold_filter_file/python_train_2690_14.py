H, W = map(int, input().split())
c = [list(map(int, input().split())) for _ in range(10)]
A = [list(map(int, input().split())) for _ in range(H)]

for k in range(10):
    for i in range(10):
        for j in range(10):
            c[i][j] = min(c[i][j], c[i][k] + c[k][j])

ans = 0
for h in range(H):
    for w in range(W):
        if A[h][w] != -1:
            ans += c[A[h][w]][1]
print(ans)
