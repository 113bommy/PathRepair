h, n = map(int, input().split())
dp = [float('inf')]*(2*(10**4)+1)
dp[0] = 0
l = [list(map(int, input().split())) for _ in range(n)]

for i in range(n):
  for j in range(h):
    dp[j+l[i][0]] = min(dp[j+l[i][0]], dp[j]+l[i][1])
    
print(min(dp[h:]))