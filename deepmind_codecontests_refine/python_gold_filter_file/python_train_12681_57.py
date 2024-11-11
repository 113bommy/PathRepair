S = input().strip()
T = input().strip()


dp = [[0] * (len(T)+1) for _ in range(len(S)+1)]

for i, s in enumerate(S):
  for j, t in enumerate(T):
    if s == t:
      dp[i][j] = dp[i-1][j-1] + 1
    else:
      dp[i][j] = max(dp[i][j-1], dp[i-1][j])
ans = []
s = (len(S)-1, len(T)-1)
while True:
  x, y = s
  if x < 0 or y < 0:
    break
  if S[x] == T[y]:
    ans.append(S[x])
    s = (x-1, y-1)
  else:
    if dp[x-1][y] > dp[x][y-1]:
      s = (x-1, y)
    else:
      s = (x, y-1)

    
print(''.join(reversed(ans)))