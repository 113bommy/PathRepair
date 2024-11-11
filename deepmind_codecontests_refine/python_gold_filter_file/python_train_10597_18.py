N, M = map(int, input().split())
V = []
INF = float("inf")
dp = [INF]*(1<<N)
dp[0] = 0
for i in range(M):
  a,b = map(int, input().split())
  c = list(map(int, input().split()))
  k = 0
  for j in range(b):
    k += 1<<(c[j]-1)
  V.append((a,k))
  dp[k] = min(dp[k],a)

for i in range(1<<N):
  for a,k in V:
    dp[i|k] = min(dp[i|k],dp[i]+dp[k])  
print(dp[-1] if dp[-1] != INF else -1)