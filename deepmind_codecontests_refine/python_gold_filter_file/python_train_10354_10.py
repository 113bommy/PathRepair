n = int(input())
l = [int(_) for _ in input().split()]

dp = [0]*(n+1)

dp[0] = -l[0]

for i in range(n-1):
    dp[i+1] = dp[i] + (l[i] - l[i+1])

print(-min(dp))
