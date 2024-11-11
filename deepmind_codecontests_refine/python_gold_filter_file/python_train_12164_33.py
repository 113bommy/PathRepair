"""
dp[t][v] = 時刻tに速度vで走っている時の今までの走行距離の最大値
dp[0][0] = 0, dp[0][i] = -inf(i>0)
条件を考える
  dp[t][v]について、時刻tにおける速度の最大値をM(t)とすると、
  v >  M[t] -> dp[v][t] = -inf
  v <= M[t] -> dp[v][t] = max(dp[t-1][v+1]+(2*v+1)/2, dp[t-1][v]+v, dp[t-1][v-1]+(2*v-1)/2)
ans = max(dp[sum(T)])
"""
from itertools import accumulate
U = 300
n = int(input())
T = [0] + list(map(lambda x:int(x)*2, input().split()))
V = list(map(lambda x:int(x)*2, input().split())) + [0]
S = sum(T)
M = [0]*(S+1)
K = list(accumulate(T))
for i in range(n):
  for j in range(K[i]+1, K[i+1]):
    M[j] = V[i]
  M[K[i+1]] = min(V[i], V[i+1])
dp = [[-float("inf")]*(U+1) for _ in range(S+1)]
dp[0][0] = 0
for t in range(1, S+1):
  for v in range(U+1):
    if v > M[t]:
      continue
    dp[t][v] = dp[t-1][v] + v
    if v > 0:
      dp[t][v] = max(dp[t][v], dp[t-1][v-1]+(2*v-1)/2)
    if v < U:
      dp[t][v] = max(dp[t][v], dp[t-1][v+1]+(2*v+1)/2)
ans = max(dp[S]) / 4
print(ans)