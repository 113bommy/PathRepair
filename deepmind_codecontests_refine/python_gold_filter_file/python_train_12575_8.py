n = int(input())
s = input()
dp = [[0 for i in range(n+1)] for j in range(n+1)]
ans = 0
for i in range(n):
  for j in range(n):
    if i == j:
      break
    if s[i] == s[j]:
      t = dp[i][j]
      if j == i-t:
        dp[i+1][j+1]=1
      else:
        dp[i+1][j+1]=1+t
        ans = max(ans, 1+t)

print(ans)
