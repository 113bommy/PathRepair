n = int(input())
s = input()

mod = 10**9 + 7

dp = [[0] * n for _ in range(n)]

for more in range(n):
    dp[0][more] = 1

for i in range(n-1):
    if s[i] == "<":
        cum = 0
        for more in reversed(range(n-1-i)):
            cum += dp[i][more+1]
            cum %= mod
            dp[i + 1][more] += cum
            dp[i + 1][more] %= mod
    else:
        cum = 0
        for more in range(n-1-i):
            cum += dp[i][more]
            cum %= mod
            dp[i+1][more] += cum
            dp[i+1][more] %= mod

print(dp[n-1][0])
