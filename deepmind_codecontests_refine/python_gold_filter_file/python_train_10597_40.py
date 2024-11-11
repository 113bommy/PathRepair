n, m = map(int, input().split())
inf = 1e9
dp = [inf] * (1 << n)
dp[0] = 0

for _ in range(m):
  a, b = map(int, input().split())
  cs = list(map(int, input().split()))
  r = 0
  for c in cs:
    r |= 1 << (c - 1)
  for i in range(1 << n):
    if dp[i | r] > dp[i] + a:
      dp[i | r] = dp[i] + a
      
if dp[(1 << n) - 1] == inf:
  print("-1")
else:
  print("{}".format(dp[(1 << n) - 1]))