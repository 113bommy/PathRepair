N, *A = map(int, open(0).read().split())

dp = [[0] * (N + 1) for _ in range(N + 1)]
for d in range(1, N + 1):
    for l in range(N - d + 1):
        r = l + d
        if (N - d) % 2 == 0:
            dp[l][r] = max(
                A[l] + dp[l + 1][r],
                A[r - 1] + dp[l][r - 1]
            )
        else:
            dp[l][r] = min(
                - A[l] + dp[l + 1][r],
                - A[r - 1] + dp[l][r - 1]
            )

print(dp[0][N])