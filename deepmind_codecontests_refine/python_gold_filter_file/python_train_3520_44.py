from itertools import accumulate


def dfs(l, r):
    if memo[l][r]:
        return dp[l][r]
    for i in range(l, r):
        dp[l][r] = min(max(0, dp[l][r]), dfs(l, i) + dfs(i + 1, r) + acc_A[r] - acc_A[l - 1])
    memo[l][r] = True
    return dp[l][r]


n = int(input())
A = list(map(int, input().split()))
acc_A = [0] + list(accumulate(A))

INF = 10 ** 18
dp = [[INF] * (n + 1) for _ in range(n + 1)]
memo = [[False] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    dp[i][i] = 0
    memo[i][i] = True


print(dfs(1, n))
