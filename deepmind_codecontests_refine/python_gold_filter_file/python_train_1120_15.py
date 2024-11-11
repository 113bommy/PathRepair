import sys
input = sys.stdin.buffer.readline

N, K = map(int, input().split())
LR = [list(map(int, input().split())) for _ in range(K)]

mod = 998244353

dp = [0]*(N+1)
tmp = 1

for i in range(N-1):
    tmp = (tmp + dp[i]) % mod
    # dp[i] = tmp
    for l, r in LR:
        dp[min(i+l, N)] = (dp[min(i+l, N)] + tmp) % mod
        dp[min(i+r+1, N)] = (dp[min(i+r+1, N)] - tmp) % mod
print(dp[N-1])