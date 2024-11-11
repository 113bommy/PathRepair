n = int(input())
A = list(map(int, input().split()))

from itertools import accumulate
B = [0] + A
B = list(accumulate(B))

INF = 10**18
dp = [[INF]*(n+1) for i in range(n+1)]
# dp[i][j]: 区間[i, j)のスライムを取り除いたコストの最小値
for i in range(n):
    dp[i][i+1] = 0
# 区間の幅(d)が狭い方から更新していく(d: 2, 3, ...n+1)
# d = 0, 1については初期化で更新した
for d in range(2, n+1):
    for i in range(n+1-d):
        j = i + d
        for k in range(i+1, j):
            dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]+B[j]-B[i])
#print(dp)
print(dp[0][n])