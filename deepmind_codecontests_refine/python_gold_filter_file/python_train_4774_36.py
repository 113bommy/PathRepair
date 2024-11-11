n,ma,mb=map(int,input().split())
abc=[list(map(int,input().split())) for i in range(n)]
dp=[[[10**9]*401 for i in range(401)] for j in range(n+1)]
dp[0][0][0]=0
for i in range(1,n+1):
  for j in range(401):
    for k in range(401):
      if j-abc[i-1][0]>=0 and k-abc[i-1][1]>=0:
        dp[i][j][k]=min(dp[i-1][j][k],dp[i-1][j-abc[i-1][0]][k-abc[i-1][1]]+abc[i-1][2])
      else:
        dp[i][j][k]=dp[i-1][j][k]
ans=10**18
for j in range(1,401):
  for k in range(1,401):
    if dp[n][j][k]<10**9 and k*ma==j*mb:
      ans=min(ans,dp[n][j][k])
if ans==10**18:
  print(-1)
else: 
  print(ans)