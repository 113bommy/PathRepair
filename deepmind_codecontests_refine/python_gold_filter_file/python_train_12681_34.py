S,T = input(),input()

dp = [[0]*(len(T)+1) for _ in range(len(S)+1)]

for i in range(1,len(S)+1):
  for j in range(1,len(T)+1):
    dp[i][j] = max(dp[i][j-1], dp[i-1][j], dp[i-1][j-1] + (S[i-1]==T[j-1]))

res = []
x,y = len(S),len(T)
v = dp[x][y]
while v > 0:
  if dp[x-1][y] == v:
    x -= 1
  elif dp[x][y-1] == v:
    y -= 1
  else:
    res.append(S[x-1])
    x -= 1
    y -= 1

  v = dp[x][y]

print(''.join(reversed(res)))