n, s = map(int, input().split())
a = list(map(int, input().split()))
dp = [[0]*(s+1) for _ in range(n+1)]
dp[0][0] = 1
mod = 998244353
for i in range(n):
    for j in range(s+1):
        dp[i+1][j] = dp[i][j]*2
        if a[i]<=j: dp[i+1][j] += dp[i][j-a[i]]
        dp[i+1][j] %= mod
print(dp[n][s])