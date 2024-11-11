N = int(input())
a = list(map(int, input().split()))
dp = [[0] * N for i in range(N)]
for i in range(N):
    dp[i][i] = a[i]
for i in range(N-1)[::-1]:
    for j in range(i+1, N):
        dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1])
print(dp[0][N-1])
