import sys
f=lambda:map(int,sys.stdin.readline().split())
h,n=f()
INF=10**9
dp=[[INF]*(h+1) for _ in range(n+1)]
dp[0][0]=0
for i in range(n):
  a,b=f()
  for j in range(h+1):
    dp[i+1][j]=min(dp[i][j],dp[i+1][max(j-a,0)]+b)
print(dp[n][h])