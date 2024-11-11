M=998244353
n,s,*l=map(int,open(0).read().split())
dp=[[0]*(s+1) for _ in '01']
dp[0][0]=1
b=0
for i in range(n):
  b^=1
  for j in range(s+1):
    dp[b][j]=dp[b^1][j]*2
    if j>=l[i]: dp[b][j]+=dp[b^1][j-l[i]]
    dp[b][j]%=M
print(dp[n%2][s])