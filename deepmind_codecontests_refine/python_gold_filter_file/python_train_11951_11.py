N, K = map(int, input().split())
H = list(map(int, input().split()))
H = [0] + H


dp = [[float('inf')] * (N + 1) for i in range(N + 1)]
dp[0][0] = 0

for i in range(1, N + 1):
    for j in range(1, N + 1):
        for x in range(i):
            dp[i][j] = min(dp[i][j], dp[x][j - 1] + max(0, H[i] - H[x]))


ans = float('inf')
for i in range(N + 1):
    ans = min(ans, dp[i][max(0,  N - K)])

print(ans)
