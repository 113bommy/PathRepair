s=input()
t=input()
dp=[[0]*(len(t)+1) for i in range(len(s)+1)]

for i in range(1,len(s)+1):
    for j in range(1,len(t)+1):
        if s[i-1]==t[j-1]:
            dp[i][j]=dp[i-1][j-1]+1

        else:
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])
    # print(dp[i])
ans=''
i,j=len(s),len(t)
while i > 0 and j > 0:
  if s[i-1]==t[j-1]:
    ans=s[i-1]+ans
    i=i-1
    j=j-1
  else:
    if dp[i-1][j]>dp[i][j-1]:
      i-=1
    else:
      j-=1
print(ans)
