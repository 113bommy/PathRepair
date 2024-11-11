H, W = map(int, input().split())
dp = [list(map(int, input().split())) for _ in range(10)]
A = [list(map(int, input().split())) for _ in range(H)]

for k in range(10):
    for i in range(10):
        for j in range(10):
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])

cost = 0
for a in A:
    for i in a:
        if i > -1:
            cost += dp[i][1]
print(cost)