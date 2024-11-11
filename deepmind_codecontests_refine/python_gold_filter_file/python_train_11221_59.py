h,n=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(n)]

dp=[float('inf')]*(h+1)
dp[0]=0
for a,b in AB:
  for i in range(h):
    if i+a>=h:
      dp[h]=min(dp[h],dp[i]+b)
    else:
      dp[i+a]=min(dp[i+a],dp[i]+b)
print(dp[h])