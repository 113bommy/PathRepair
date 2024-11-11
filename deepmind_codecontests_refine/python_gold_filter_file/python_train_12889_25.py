N, W = map(int, input().split())
dp = [[float("inf")] * (10**5 + 1) for i in range(N+1)]
dp[0][0] = 0

for i in range(N):
  w, v = map(int, input().split())
  for j in range(10**5 + 1):
    dp[i+1][j] = min(dp[i][j], dp[i][j-v] + w) if j >= v and dp[i][j-v] + w <= W else dp[i][j]

ans = 0
for i in range(10**5 + 1):
  if dp[-1][i] <= W:
    ans = i
print(ans)