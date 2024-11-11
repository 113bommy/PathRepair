n=int(input())
arr=list(map(int,input().split()))
dp=[[0]*n for _ in range(n)]
for i in range(n):
  if n%2==0:
    dp[i][i]=-arr[i]
  else:
    dp[i][i]=arr[i]
for i in range(1,n):
  for j in range(n-i):
    if (n-i)%2==0:
      dp[j][j+i]=min(dp[j][j+i-1]-arr[j+i],dp[j+1][j+i]-arr[j])
    else:
      dp[j][j+i]=max(dp[j][j+i-1]+arr[j+i],dp[j+1][j+i]+arr[j])
print(dp[0][n-1])