N = int(input())
K = int(input())
n = list(map(int, str(N)))
dp = [[[0] * 5 for __ in range(2)] for _ in range(101)]
l = len(n)
dp[0][0][0] = 1
for i in range(l):
    for smaller in range(2):
        for j in range(4):
            for x in range((9 if smaller else n[i]) + 1):
                dp[i + 1][smaller or x < n[i]][j + 1 if x != 0 else j] += dp[i][smaller][j]
print(dp[l][0][K] + dp[l][1][K])