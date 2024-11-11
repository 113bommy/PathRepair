n, s = map(int, input().split())
a = list(map(int, input().split()))
mod = 998244353
dp = [[0] * (s + 1) for i in range(n + 1)]
dp[0][0] = 1
for i in range(1, n + 1):
    for j in range(s + 1):
        dp[i][j] += dp[i - 1][j] * 2
        dp[i][j] %= mod
        if a[i - 1] + j <= s:
            dp[i][a[i - 1] + j] += dp[i - 1][j]
            dp[i][a[i - 1] + j] %= mod
print(dp[n][s])