N, M = map(int, input().split())
key = []
for _ in range(M):
  a, b = map(int, input().split())
  s = 0
  C = list(map(lambda x:int(x)-1, input().split()))
  for c in C:
    s |= 1<<c
  key += [(s, a)]
  
dp = [float('inf')]*(1<<N)
dp[0] = 0
for s in range(1<<N):
  for i in range(M):
    t = s | key[i][0] # 遷移先
    cost = dp[s] + key[i][1]
    dp[t] = min(dp[t], cost)
if dp[-1] == float('inf'):
  print(-1)
else:
  print(dp[-1])




