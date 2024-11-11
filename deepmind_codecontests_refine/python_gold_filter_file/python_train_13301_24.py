R, C, K = map(int, input().split())
rcv = [list(map(int, input().split())) for _ in range(K)]

board = [[0] * (C + 1) for _ in range(R + 1)]
for r, c, v in rcv:
    board[r][c] = v

dp = [[[0] * (C + 1) for _ in range(R + 1)] for _ in range(4)]

for r in range(1, R + 1):
    for c in range(1, C + 1):
        v = board[r][c]
        for i in range(4):
            dp[0][r][c] = max(dp[0][r][c], dp[i][r-1][c])
            dp[1][r][c] = max(dp[1][r][c], dp[i][r-1][c] + v)

            dp[i][r][c] = max(dp[i][r][c], dp[i][r][c-1])
            if i > 0:
                dp[i][r][c] = max(dp[i][r][c], dp[i-1][r][c-1] + v)

ans = 0
for i in range(4):
    ans = max(ans, dp[i][R][C])

print(ans)
