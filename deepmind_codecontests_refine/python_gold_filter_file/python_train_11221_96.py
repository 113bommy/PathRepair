h,n = map(int,input().split())
spel = [list(map(int,input().split())) for i in range(n)]
dp = [float('inf')]*(h+1)
dp[0] = 0
for i in range(h):
  for damage,cost in spel:
    n_i = min(i+damage,h)
    dp[n_i] = min(dp[n_i],dp[i]+cost)
print(dp[h])