n,K = map(int,input().split())
a = [0]+list(map(int,input().split()))+[0]
INF = float("inf")
n += 1
dp = [[[INF for i in range(K+1)] for j in range(n+1)] for k in range(n+1)]
dp[0][0][0] = 0
mx = 0
for i in range(1,n+1):
  x = a[i]
  for j in range(i):
    for k in range(1,min(K,i)+1):
      dp[i][j][k] = dp[i-1][j][k-1]
  for k in range(min(K,i)+1):
    for l in range(1,i+1):
      dp[i][i][k] = min(dp[i][i][k],dp[i-1][i-l][k]+max(0,x-a[i-l]))
print(dp[n][n][K])