s = input()
t = input()

dp = [[0]*(len(s)+1) for _ in range(len(t)+1)]

for i in range(len(t)):
  for j in range(len(s)):
    if t[i] == s[j]:
      dp[i+1][j+1] = dp[i][j] + 1
    else:
      dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])

i = len(t)
j = len(s)
ans = ''
while i >= 0 and j >= 0:
  if dp[i][j] == dp[i-1][j]:
    i -= 1
  elif dp[i][j] == dp[i][j-1]:
    j -= 1
  else:
    i -= 1
    j -= 1
    ans = ans + t[i]
print(ans[::-1])