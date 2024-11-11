from itertools import accumulate

INF = float('inf')

N = int(input())
As = list(map(int, input().split()))

accAs = [0] + list(accumulate(As))

dp = [[0] * (N) for _ in range(N)]
for num in range(2, N+1):
    for i in range(N-num+1):
        cost = INF
        for j in range(1, num):
            cost = min(cost, dp[i][i+j-1] + dp[i+j][i+num-1])
        dp[i][i+num-1] = accAs[i+num] - accAs[i] + cost

print(dp[0][N-1])
