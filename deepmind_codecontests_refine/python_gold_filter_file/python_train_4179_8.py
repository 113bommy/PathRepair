import math

h = 'hard'
n = int(input())
s = input()
a = list(map(int, input().split()))

dp = [[math.inf for _ in range(5)] for _ in range(n+1)]

dp[0][0] = 0
for i in range(0, n):
    for j in range(0, 4):
        if s[i] == h[j]:
            dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j])
        else:
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j])
        dp[i+1][j] = min(dp[i+1][j], dp[i][j] + a[i])

print(min(dp[n][:4]))
