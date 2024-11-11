mod = 998244353
s = list(map(int, list(input())))
n = len(s)
dp = [[0]*(sum(s)+1) for _ in range(2*n+1)]
dp[0][0] = 1
curr = curb = 0
for i in range(2*n):
  if i < n:
    curb += s[i]
    curr += 2 - s[i]
  for j in range(min(i, curb)+1):
    if dp[i][j]:
      dp[i][j] %= mod
      if i - j < curr:
        dp[i+1][j] += dp[i][j]
      if j < curb:
        dp[i+1][j+1] += dp[i][j]
print(dp[2*n][curb] % mod)   