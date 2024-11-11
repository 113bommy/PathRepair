import sys
from collections import defaultdict as dd
input = sys.stdin.readline
S = list(input())[: -1]
N = len(S)
cs = [0] * (N + 1)
a = ord("a")
table = [1 << x for x in range(27)]
for i in range(N):
  cs[i + 1] = cs[i] ^ table[(ord(S[i]) - a)]
d = dd(lambda: N + 1)

dp = [N] * (N + 1)
dp[0] = 0
d[0] = 0
for i in range(N):
  for j in range(26):
    x = d[cs[i + 1] ^ table[j]]
    #print(cs[i + 1], table[j], d[x])
    if x >= N + 1: continue
    dp[i + 1] = min(dp[i + 1], x + 1)
  x = d[cs[i + 1]]
  if x <= N: dp[i + 1] = min(dp[i + 1], x + 1)
  d[cs[i + 1]] = min(x, dp[i + 1])
print(dp[-1])