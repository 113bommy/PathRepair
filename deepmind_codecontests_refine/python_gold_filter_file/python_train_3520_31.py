# https://atcoder.jp/contests/dp/tasks/dp_n

import itertools as it

INF = 1 << 62
N = int(input())
xs = [int(s) for s in input().split()]
acc = list(it.accumulate([0] + xs))

dp = [[INF] * (N + 1) for _ in range(N)]

for i in range(N):
    dp[i][i + 1] = 0

for w in range(2, N + 1):
    for i in range(N - w + 1):
        j = i + w
        subcost = min(dp[i][k] + dp[k][j] for k in range(i + 1, j))
        dp[i][j] = subcost + acc[j] - acc[i]

print(dp[0][N])
