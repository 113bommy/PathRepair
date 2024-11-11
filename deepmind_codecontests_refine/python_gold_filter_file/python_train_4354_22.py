N = int(input())
A = list(map(int, input().split()))

dp = [[0] * (N + 1) for _ in range(N + 1)]

for d in range(1, N + 1):
    for i in range(N - d + 1):
        j = i + d
        if (N-d) % 2 == 1:
            dp[i][j] = min(dp[i+1][j]-A[i], dp[i][j-1]-A[j-1])
        else:
            dp[i][j] = max(dp[i+1][j]+A[i], dp[i][j-1]+A[j-1])

ans = dp[0][N]
print(ans)
