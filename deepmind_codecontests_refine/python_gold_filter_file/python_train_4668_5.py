S = input()
K = int(input())
N = len(S)

# MLE対策
if K * 2 >= N-1:
    print(N)
    exit()

dp = [[[0 for _ in range(K+1)] for _ in range(N)] for _ in range(N)]
for i in range(N):
    for k in range(K+1):
        dp[i][i][k] = 1

for _j in range(1, N):
    for i in range(N):
        j = i + _j
        if j < N:
            for k in range(K+1):
                dp[i][j][k] = max(dp[i][j][k], dp[i+1][j][k], dp[i][j-1][k])
                if _j == 1:
                    if S[i] == S[j]:
                        dp[i][j][k] = 2
                    else:
                        if k+1 <= K:
                            dp[i][j][k+1] = 2
                else:
                    if S[i] == S[j]:
                        dp[i][j][k] = max(dp[i][j][k], dp[i+1][j-1][k] + 2)
                    else:
                        if k+1 <= K:
                            dp[i][j][k+1] = max(dp[i][j][k], dp[i+1][j-1][k] + 2)

print(max(dp[0][N-1]))

