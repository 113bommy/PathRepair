n, m, k = map(int, input().split())
dp = [[0] * (n + 1) for i in range(n)]
MOD = 998244353
dp[0][0] = m

for i in range(1, n):
    for j in range(k + 1):
        dp[i][j + 1] += dp[i - 1][j] * (m - 1)
        dp[i][j] += dp[i - 1][j]
        dp[i][j + 1] %= MOD
        dp[i][j] %= MOD

print(dp[n - 1][k])