H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
B = [list(map(int, input().split())) for _ in range(H)]

Z = 1000

dp = [[0] * (W + 1) for _ in range(H + 1)]
dp[0][0] = (1 << Z)

for h in range(H):
    for w in range(W):
        d = dp[h][w]
        k = abs(A[h][w] - B[h][w])

        dp[h + 1][w] |= (d << k) | (d >> k)
        dp[h][w + 1] |= (d << k) | (d >> k)

ans = 10**18
for a in (dp[H][W - 1], dp[H - 1][W]):
    for d in range(Z * 2 + 10):
        if a & (1 << d) != 0:
            ans = min(ans, abs(d - Z))
print(ans)
