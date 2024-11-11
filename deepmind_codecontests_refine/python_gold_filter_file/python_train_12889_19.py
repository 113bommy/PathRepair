N, W = map(int, input().split())
dp = [[1000000001 for i in range(N*1000+1)] for j in range(N+1)]
dp[0][0] = 0
for j in range(N):
    w, v = map(int, input().split())
    for k in range(N*1000+1):
        dp[j+1][k] = min(dp[j][k-v] + w, dp[j][k])


ans = 0
for i in range(N*1000+1):
    if dp[N][i] <= W:
        ans = max(ans, i)
print(ans)
