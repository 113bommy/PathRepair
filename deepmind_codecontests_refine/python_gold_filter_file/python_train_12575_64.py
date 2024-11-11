n=int(input())
s=input()
dp=[n*[0]for _ in range(n)]
for i in range(n):
  if s[i]==s[0]:
    dp[i][0]=dp[0][i]=1
for i in range(1,n):
  for j in range(1,n):
    if s[i]==s[j]:
      dp[i][j]=dp[i-1][j-1]+1
ans=0
for i in range(n-1):
  for j in range(i+1,n):
    if i<j-dp[i][j]+1:ans=max(ans,dp[i][j])
print(ans)