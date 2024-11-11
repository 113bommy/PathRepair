s=input()
t=input()
n=len(s)
m=len(t)
dp=[[0 for i in range(m+1)] for j in range(n+1)]
for i in range(n):
  for j in range(m):
    if s[i]==t[j]:
      dp[i+1][j+1]=dp[i][j]+1
    else:
      dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])
ans=''
a=n
b=m
while a>0 and b>0:
  if dp[a][b]==dp[a-1][b]:
    a-=1
  elif dp[a][b]==dp[a][b-1]:
    b-=1
  else:
    a-=1
    b-=1
    ans=s[a]+ans
print(ans)