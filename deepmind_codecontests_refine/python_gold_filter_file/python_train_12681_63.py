s=str(input())
t=str(input())
ls=len(s)
lt=len(t)

dp=[[0 for i in range(lt+1)]for j in range(ls+1)]
for i in range(ls):
  for j in range(lt):
    if s[i]==t[j]:
      dp[i+1][j+1]=dp[i][j]+1
    else:
      dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])

ans=""
x=ls
y=lt
while x>0 and y>0:
  if dp[x][y]==dp[x-1][y]:
    x-=1
  elif dp[x][y]==dp[x][y-1]:
    y-=1
  else:
    ans=s[x-1]+ans
    x-=1
    y-=1
print(ans)