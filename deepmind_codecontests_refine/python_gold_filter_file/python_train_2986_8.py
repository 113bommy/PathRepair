
n = int(input())
size = [int(x) for x in input().split()]
costs = [int(x) for x in input().split()]
dp = [10000000000 for _ in range(n)]
best = 1000000000
for i in range(n):
    for k in range(0,i):
        if size[k]<size[i]:
            dp[i] = min(dp[i],costs[k]+costs[i])
            best = min(dp[k]+costs[i],best)
if best==1000000000:
    print(-1)
else:
    print(best)