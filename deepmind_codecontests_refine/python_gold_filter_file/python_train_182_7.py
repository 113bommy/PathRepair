n=input()
k=int(input())
l=len(n)
dp=[[[0 for _ in range(2)] for _ in range(5)] for _ in range(l+1)]
dp[0][1][1]=int(n[0])-1
dp[0][1][0]=1
for i in range(1,l):
  for j in range(4):
    b=i-1
    now=int(n[i])
    if now==0:
      dp[i][j][0]+=dp[b][j][0]
    else:
      dp[i][j][1]+=dp[b][j][0]
      dp[i][j+1][1]+=dp[b][j][0]*(now-1)
      dp[i][j+1][0]+=dp[b][j][0]
    dp[i][j][1]+=dp[b][j][1]
    dp[i][j+1][1]+=dp[b][j][1]*9
  dp[i][1][1]+=9
print(dp[l-1][k][0]+dp[l-1][k][1])
           
