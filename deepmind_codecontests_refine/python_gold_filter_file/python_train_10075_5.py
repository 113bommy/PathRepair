n,s = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
mod = 998244353
dp = [[0 for i in range(s+1)] for j in range(n+1)]
dp[0][0] = 1
for i in range(n):
    for x in range(s+1):
        dp[i+1][x] = 2*dp[i][x]
        if x-a[i] >= 0:
            dp[i+1][x] += dp[i][x-a[i]]
        dp[i+1][x] %= mod

print(dp[n][s])