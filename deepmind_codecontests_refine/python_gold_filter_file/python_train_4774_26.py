n, ma, mb = map(int, input().split())
U = 400
dp = [[[float("inf")]*(U+1) for _ in range(U+1)] for i in range(n+1)]
dp[0][0][0] = 0
for i in range(n):
  a, b, c = map(int, input().split())
  for j in range(U+1):
    for k in range(U+1):
      if j<a or k<b:
        dp[i+1][j][k] = dp[i][j][k]
      else:
        dp[i+1][j][k] = min(dp[i][j][k], dp[i][j-a][k-b]+c)
ans = float("inf")
for i in range(1, 1+U//max(ma, mb)):
  na, nb = i*ma, i*mb
  ans = min(ans, dp[-1][na][nb])
if ans == float("inf"):
  print(-1)
else:
  print(ans)