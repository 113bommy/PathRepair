n,m = map(int, input().split())
mod = 10**9 + 7
a = list(map(int, input().split()))
dp = [[[0]*256 for _ in range(n+1)]for i in range(n+1)]
dp[0][0][0] = 1
for i in range(n):
  x = a[i]
  dp[i+1][0] = dp[i][0][:]
  for j in range(n):
    for k in range(256):
      dp[i+1][j+1][k] = (dp[i][j+1][k] + dp[i][j][k^x])%mod
f = 1
ans = 0
for j in range(1,n+1):
  f = f*j%mod
  ans += dp[n][j][m]*f
  ans %= mod
print(ans)
