s=input()
t=input()
a=len(s)
b=len(t)
dp=[[0]*(b+1) for i in range(a+1)]
for i in range(a):
  for j in range(b):
    if s[i]==t[j]:
      dp[i+1][j+1]=dp[i][j]+1
    else:
      dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j])
res=''
while a!=0 and b!=0:
  if dp[a][b]==dp[a-1][b]:
    a-=1
  elif dp[a][b]==dp[a][b-1]:
    b-=1
  else:
    a-=1
    b-=1
    res=s[a]+res
print(res)