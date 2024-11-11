mod=998244353
n,s=map(int,input().split())
arr=list(map(int,input().split()))
dp=[[0]*(s+1) for _ in range(n+1)]
dp[0][0]=1
for i in range(1,n+1):
  val=arr[i-1]
  for j in range(s,-1,-1):
    dp[i][j]=2*dp[i-1][j]
    dp[i][j]%=mod
    if j-val>=0 and dp[i-1][j-val]!=0:
      dp[i][j]+=dp[i-1][j-val]
      dp[i][j]%=mod
print(dp[n][s])