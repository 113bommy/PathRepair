N,W = map(int,input().split())

items = [tuple(map(int,input().split())) for i in range(N)]

from collections import defaultdict
dp = defaultdict(int) # w -> v
dp[0] = 0

for w,v in items:
  for tw,tv in list(dp.items()):
    if tw+w <= W:
      dp[tw+w] = max(tv+v, dp[tw+w])

print(max(dp.values()))