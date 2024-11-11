n,s,*a=map(int,open(0).read().split())
mod=998244353
dp=[[0]*(s+1) for _ in range(n+1)]
dp[0][0]=pow(2,n,mod)
for i in range(n):
  for j in range(s+1):
    dp[i+1][j]+=dp[i][j]
    dp[i+1][j]%=mod
    if j+a[i]<=s:
      dp[i+1][j+a[i]]+=dp[i][j]*(mod+1)//2
      dp[i+1][j+a[i]]%=mod
print(dp[n][s])