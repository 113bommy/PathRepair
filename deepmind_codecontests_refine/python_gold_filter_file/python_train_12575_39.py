n = int(input())
s = str(input())

dp = [[0]*(n+1) for i in range(n+1)]
#dp[n-1][n-1] = 1

for i in reversed(range(n)):
  for j in reversed(range(n)):
    if s[i] == s[j]:
      dp[i][j] = dp[i+1][j+1]+1

#print(dp)

ans = 0
for i in range(n-1):
  for j in range(i, n):
    ans = max(ans, min(dp[i][j], j-i))
    
print(ans)
