n,a=int(input()),list(map(int,input().split()));dp=[[None]*n for _ in range(n)]
for i in range(n):dp[i][i]=a[i]
for j in range(1,n):
  for i in range(n-j):dp[i][j+i]=max(a[i]-dp[i+1][j+i],a[j+i]-dp[i][j+i-1])
print(dp[0][-1])