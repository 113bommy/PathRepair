s = input()
t = input()
n = len(s)
m = len(t)
dp = [[0]*(m+1) for _ in range(n+1)]
for i in range(n):
  for j in range(m):
    if s[i] == t[j]:
      dp[i+1][j+1] = dp[i][j] + 1
    else:
      dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j])
i,j = n,m
ans = ""
while i and j:
  if dp[i][j] == dp[i-1][j]:
    i -= 1
  elif dp[i][j] == dp[i][j-1]:
    j -= 1
  else:
    i -= 1
    j -= 1
    ans += s[i]
print(ans[::-1])