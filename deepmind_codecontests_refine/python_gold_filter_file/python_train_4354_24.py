n = int(input())
a = list(map(int, input().split()))

dp = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(n)[::-1]:
    for j in range(n + 1):
        if i >= j:
            continue
        dp[i][j] = max(a[j - 1] - dp[i][j - 1], a[i] - dp[i + 1][j])

print(dp[0][n])
