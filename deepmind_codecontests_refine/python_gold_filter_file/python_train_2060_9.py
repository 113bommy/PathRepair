n = input()[::-1]
dp = [[0, 0] for i in range(len(n) + 1)]
dp[0][1] = 1
for i in range(len(n)):
    dp[i + 1][0] = min(dp[i][0] + int(n[i]), dp[i][1] - int(n[i]) + 10)
    dp[i + 1][1] = min(dp[i][0] + int(n[i]) + 1, dp[i][1] - int(n[i]) + 9)
print(dp[len(n)][0])