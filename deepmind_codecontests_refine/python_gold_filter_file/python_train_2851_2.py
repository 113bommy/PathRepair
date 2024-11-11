n = int(input())
t = [0] * n
w = [0] * n

for i in range(n):
    t[i], w[i] = map(int, input().split())

dp = [[float("inf")] * (2 * n + 1) for i in range(n)]
dp[0][t[0]] = 0
dp[0][0] = w[0]
for i in range(n - 1):
    for j in range(2 * n + 1):
        a = dp[i][j]
        if a != float("inf"):
            dp[i + 1][j + t[i + 1]] = min(dp[i + 1][j + t[i + 1]], dp[i][j])
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + w[i + 1])
# 12 3 15 5 1
ans = float("inf")
for j in range(2 * n + 1):
    if dp[n - 1][j] <= j:
        ans = min(ans, j)
print(ans)