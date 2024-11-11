mod = 998244353

n,s = map(int, input().split())
al = list(map(int, input().split()))

dp = [[0]*(s+1) for _ in range(n+1)]
dp[0][0] = 1

for i in range(n):
    a = al[i]
    for j in range(s+1):
        dp[i+1][j] += 2*dp[i][j]
        dp[i+1][j] %= mod

        if j+a<=s:
            dp[i+1][j+a] += dp[i][j]
            dp[i+1][j+a] %= mod

print(dp[n][s])