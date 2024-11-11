S = input()
T = input()

N = len(S)
M = len(T)
dp = [[0 for _ in range(N+1)] for _ in range(M+1)]

for i in range(1, M+1):
    for j in range(1, N+1):
        if S[j-1]==T[i-1]:
            dp[i][j] += dp[i-1][j-1]+1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

i, j = M, N
lcs = ""
while i>0 and j>0:
    if T[i-1]==S[j-1]:
        lcs += T[i-1]
        i -= 1
        j -= 1
    else:
        if dp[i-1][j]>dp[i][j-1]:
            i -= 1
        else:
            j -= 1
print(lcs[::-1])