s = input()
t = input()
n = len(s)
m = len(t)

dp = [[0]*(m+1) for _ in range((n+1))]

for i in range(n):
  for j in range(m):
    if s[i]==t[j]:
      dp[i+1][j+1] = dp[i][j] + 1
    else:
      dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
      
ans = ''
i = len(s)
j = len(t)
while i>0 and j>0:
  if dp[i][j] == dp[i-1][j]:
    i-=1    
  elif dp[i][j] == dp[i][j-1]:
    j-=1
  else:
    i-=1
    j-=1
    ans = s[i]+ans
    
print(ans)    