n=int(input())
a=list(map(int,input().split()))
dp=[[0 for i in range(n+1)] for j in range(n+1)]

for len in range(1,n+1):
  for i in range(n+1):
    if i+len>n:
      break
    j=i+len
    if (n - len) % 2 == 0:
      dp[i][j] = max(dp[i + 1][j] + a[i], dp[i][j - 1] + a[j - 1])
      #print(len,dp)
    else:
      dp[i][j] = min(dp[i + 1][j] - a[i], dp[i][j - 1] - a[j - 1])
      #print(len,dp)
print(dp[0][n])