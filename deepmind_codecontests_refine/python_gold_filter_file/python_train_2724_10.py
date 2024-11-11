n1, n2, k1, k2 = map(int, input().strip().split())
dp = [[[0, 0] for i in range(n2+1)] for i in range(n1+1)]
mod = 10**8
for i in range(n2+1):
    if i <= k2:
        dp[0][i][1] = 1
for i in range(n1+1):
    if i <= k1:
        dp[i][0][0] = 1

for i in range(1, n1+1):
    for j in range(1, n2+1):
        xInd = i-k1-1
        yInd = j-k2-1
        dp[i][j][0] = sum(dp[i-1][j])%mod
        dp[i][j][1] = sum(dp[i][j-1])%mod
        if xInd >= 0:
            dp[i][j][0] = dp[i][j][0]-dp[xInd][j][1]
        if yInd >= 0:
            dp[i][j][1] = dp[i][j][1]-dp[i][yInd][0]
print(sum(dp[-1][-1])%mod)
# print("#########")
# for i in dp:
#     print(i)
