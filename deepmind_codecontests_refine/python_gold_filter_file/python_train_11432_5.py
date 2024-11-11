N, X = map(int, input().split())
S = sorted(list(map(int, input().split())))
mod = 10 ** 9 + 7
dp = [[0 for _ in range(X+1)] for _ in range(N+1)]
dp[1] = [i % S[0] for i in range(X+1)]
S = [None] + S

for i in range(2, N+1):
    for j in range(X+1):
        dp[i][j] = (dp[i-1][j]*(i-1) + dp[i-1][j%S[i]]) % mod


print(dp[-1][-1])