dp = [[0]*3001 for _ in range(3001)]
n,s = (int(num) for num in input().split())
a = [int(num) for num in input().split()]
MOD = 998244353
dp[0][0] = 1
for i in range(1,n+1):
    for j in range(s+1):
        dp[i][j] = (dp[i-1][j] * 2) % MOD
        if j >= a[i-1]:
            dp[i][j] = (dp[i][j] + dp[i-1][j-a[i-1]])%MOD
            
print(dp[n][s])