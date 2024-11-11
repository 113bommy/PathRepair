h,n = map(int,input().split())
ab = [list(map(int,input().split())) for _ in range(n)]

dp = [float("inf")]*(h+1)
dp[0] = 0

for i in range(h):
  for d,c in ab:
    hp = min(i+d,h)
    dp[hp] = min(dp[hp],dp[i]+c)

print(dp[-1])