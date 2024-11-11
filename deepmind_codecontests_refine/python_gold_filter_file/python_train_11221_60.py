from sys import maxsize

h, n = map(int, input().split())
m = [list(map(int, input().split())) for _ in range(n)]

dp = [0] + [maxsize]*h
for a, b in m:
    for i in range(h+1):
        dp[min(i+a, h)] = min(dp[min(i+a, h)], dp[i]+b)
print(dp[h])
