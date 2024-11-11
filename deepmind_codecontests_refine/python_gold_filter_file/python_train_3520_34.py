import sys
sys.setrecursionlimit(10**9)

n = int(input())
A = list(map(int, input().split()))

memo = [[float('inf')]*410 for _ in range(410)]
visit = [[False]*410 for _ in range(410)]

from itertools import accumulate
B = [0]+A
B = list(accumulate(B))

def dp(l, r):
  if l == r:
    return 0
  if visit[l][r]:
    return memo[l][r]
  visit[l][r] = True
  res = float('inf')
  for c in range(l, r):
    res = min(res, dp(l, c)+dp(c+1, r)+B[r+1]-B[l])
  memo[l][r] = res
  return res

print(dp(0, n-1))