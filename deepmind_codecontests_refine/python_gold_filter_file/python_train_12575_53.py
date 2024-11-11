N = int(input())
S = input()
dp = [[0]*(N+1) for _ in range(N+1)]
res = 0
for i in range(N-1,-1,-1):
  for j in range(N-1,i,-1):
    if S[i]==S[j]:
      dp[i][j]=max(dp[i+1][j+1]+1,dp[i][j])
    res = max(res,min(j-i,dp[i][j]))
print(res)