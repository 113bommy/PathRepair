s=input()
m=int(input())
n=len(s)
if n==1:
  print([0,int(s)][m==1])
  exit()
dp=[[[0]*2 for _ in range(m+1)] for _ in range(n)]
dp[0][0][1]=1
dp[0][1][1]=int(s[0])-1
dp[0][1][0]=1
for i in range(1,n):
  for j in range(m+1):
    if j:
      dp[i][j][1]+=9*dp[i-1][j-1][1]
      if s[i]!='0':
        dp[i][j][0]+=dp[i-1][j-1][0]
        dp[i][j][1]+=(int(s[i])-1)*dp[i-1][j-1][0]
    if s[i]=='0':dp[i][j][0]+=dp[i-1][j][0]
    dp[i][j][1]+=dp[i-1][j][1]
    if s[i]!='0':dp[i][j][1]+=dp[i-1][j][0]
print(sum(dp[-1][-1]))