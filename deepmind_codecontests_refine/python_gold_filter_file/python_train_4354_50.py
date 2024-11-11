N = int(input())
A = list(map(int, input().split()))
dp = [[0] * (N+1) for _ in range(N+1)]

for width in range(1, N+1):
    for i in range(N-width+1):
        j = i + width

        if (N - width) % 2 == 0:
            dp[i][j] = max(dp[i+1][j] + A[i], dp[i][j-1] + A[j-1])
        else:
            dp[i][j] = min(dp[i+1][j] - A[i], dp[i][j-1] - A[j-1])

print(dp[0][N])