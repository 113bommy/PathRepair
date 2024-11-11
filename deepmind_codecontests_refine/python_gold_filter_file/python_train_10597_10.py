n, m = map(int, input().split())
p = 2 ** n
inf = 10 ** 9
dp = [inf] * p
dp[0] = 0
for i in range(m):
  a, b = map(int, input().split())
  c = sum([2 ** (int(j) - 1) for j in list(input().split())])
  for k in range(p):
    if dp[k|c] > dp[k] + a:
      dp[k|c] = dp[k] + a
      
if dp[-1] == inf:
  print(-1)
else:
  print(dp[-1])