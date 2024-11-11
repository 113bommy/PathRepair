import sys
input = sys.stdin.buffer.readline
H, W, K = map(int, input().split())
B = {}
for _ in range(K):
    r, c, v = map(int, input().split())
    B[(r, c)] = v

dp = [[0]*4 for _ in range(W+1)]

for i in range(1, H+1):
    for j in range(1, W+1):
        if (i, j) in B:
            v = B[(i, j)]
            dp[j][0] = max(dp[j-1][0], dp[j][0], dp[j][1], dp[j][2], dp[j][3])
            dp[j][1] = max(dp[j-1][1], dp[j][0]+v)
            dp[j][2] = max(dp[j-1][2], dp[j-1][1]+v)
            dp[j][3] = max(dp[j-1][3], dp[j-1][2]+v)
        else:
            dp[j][0] = max(dp[j-1][0], dp[j][0], dp[j][1], dp[j][2], dp[j][3])
            dp[j][1] = dp[j-1][1]
            dp[j][2] = dp[j-1][2]
            dp[j][3] = dp[j-1][3]

print(max(dp[-1]))
