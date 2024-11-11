N, W = map(int, input().split())

INF = 10**11 + 1
dp = [[INF]*(10**5 + 1) for _ in range(N+1)]
dp[0][0] = 0

for i in range(N):
  w, v = map(int, input().split())
  for j in range(10**5 + 1):
    dp[i+1][j] = min(dp[i][j], dp[i][max(0, j-v)] + w)

ans = 0
    
for i, x in enumerate(dp[-1]):
  if x <= W:
    ans = i

print(ans)