H, N = map(int, input().split())
AB = [list(map(int, input().split())) for i in range(N)]

dp = [float("INF")] * 10 ** 5
dp[0] = 0

for h in range(H):
    for a, b in AB:
        dp[h+a] = min(dp[h] + b, dp[h+a])

print(min(dp[H:]))