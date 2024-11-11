n=int(input())
mod=10**9+7
dp=[[0]*2 for i in range(n)]
dp[0][1]=1
for i in range(1,n):
  if i%2==0:
    dp[i][0]=dp[i-1][0]
    dp[i][1]=(dp[i-1][1]+dp[i-1][0]+1)%mod
  else:
    dp[i][0]=(dp[i-1][0]+dp[i-1][1]+1)%mod
    dp[i][1]=dp[i-1][1]
print((dp[n-1][0]+dp[n-1][1])%mod)