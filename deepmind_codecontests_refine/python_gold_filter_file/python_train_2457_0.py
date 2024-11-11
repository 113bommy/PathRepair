import sys

n = int(input()) + 1
a = [0] + list(map(int, input().split()))
mod7 = [x % 7 for x in a]

dp = [[0]*n for _ in range(n)]
maxnum = [0]*(10**5+10)
ans = 0

for i in range(n):
    maxmod = [0]*7

    for j in range(n):
        maxnum[a[j]] = 0

    for j in range(i):
        maxnum[a[j]] = max(maxnum[a[j]], dp[j][i])
        maxmod[mod7[j]] = max(maxmod[mod7[j]], dp[j][i])

    for j in range(i+1, n):
        dp[i][j] = max(
            maxnum[a[j]-1],
            maxnum[a[j]+1],
            maxmod[mod7[j]],
            dp[0][i]
        ) + 1

        maxnum[a[j]] = max(maxnum[a[j]], dp[i][j])
        maxmod[mod7[j]] = max(maxmod[mod7[j]], dp[i][j])
        ans = max(ans, dp[i][j])

print(ans)
