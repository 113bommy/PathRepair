H, N = map(int, input().split())

dp = [[0] + [1e20] * (H) for _ in range(N)]

for i in range(N):
    A, B = map(int, (input().split()))
    for j in range(1, H + 1):
        dp[i][j] = min(dp[i - 1][j], dp[i][max(j - A, 0)] + B)

print(dp[-1][-1])