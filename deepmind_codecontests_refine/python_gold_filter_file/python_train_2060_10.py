s = input(); n = len(s)
dp = [ [0,1<<32] for i in range(n+1) ]
for i in range(n):
  d = ord(s[i])-ord('0')
  dp[i+1][0] = min(dp[i][0], dp[i][1])+d
  dp[i+1][1] = min(dp[i][0], dp[i][1]-2)+11-d
print(min(dp[n][0],dp[n][1]))