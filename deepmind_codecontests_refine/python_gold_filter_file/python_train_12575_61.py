n = int(input())
s = input()

l = len(s)

dp = [[0] * (l + 1) for _ in range(l + 1)]
dp[0][0] = 1

ans = 0
for i, ei in enumerate(s, 1):
    for j, ej in enumerate(s[i:], i+1):
        if ei == ej:
            dp[i][j] = min(dp[i-1][j-1] + 1, j - i)
            ans = max(ans, dp[i][j])

print(ans)
