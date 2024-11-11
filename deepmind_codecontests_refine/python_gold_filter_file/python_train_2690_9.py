H, W = map(int, input().split())
c = [list(map(int, input().split())) for k in range(10)]
A = [list(map(int, input().split())) for k in range(H)]

for p in range(10):
    for q in range(10):
        for r in range(10):
            c[q][r] = min(c[q][r], c[q][p]+c[p][r])

ans = 0
for k in range(H):
    for l in range(W):
        if A[k][l] >= 0:
            ans += c[A[k][l]][1]
print(ans)
