h, n = map(int, input().split())
spells = [list(map(int, input().split())) for _ in range(n)]
INF = 10 ** 9
dp = [INF] * (h + 1)
dp[0] = 0

for i in range(h):
    for a, b in spells:
        ni = min(i + a, h)
        dp[ni] = min(dp[ni], dp[i] + b)

print(dp[h])