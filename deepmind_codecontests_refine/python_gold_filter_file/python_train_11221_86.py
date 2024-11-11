INF = 1001001001
H, N = map(int, input().split())
ab = [list(map(int, input().split())) for _ in range(N)]
dp = [INF] * (20000)
dp[0] = 0
for a,b in ab:
    for j in range(H):
        if dp[j+a] > dp[j] + b:
            dp[j+a] = dp[j] + b
print(min(dp[H:]))