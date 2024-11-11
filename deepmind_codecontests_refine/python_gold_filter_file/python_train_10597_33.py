n, m = map(int, input().split())
dp = [ [float("inf")]*(2**n) for _ in range(m) ]
dp[0][0] = 0
for i in range(1, m):
  a, b = map(int, input().split())
  k = set(map(int, input().split()))
  c = 0
  for l in k:
    c += 2**(l-1)
  for j in range(2**n):
    dp[i][j] = min(dp[i-1][j&(~c)]+a, dp[i-1][j])

if dp[m-1][2**n-1] == float("inf"):
  print(-1)
else:
  print(dp[m-1][2**n-1])