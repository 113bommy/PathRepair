n = int(input())
s = input()
dp = [1] * n
mod = 10 ** 9 + 7
for ind, i in enumerate(s):
    dp2 = [0] * n
    if i == ">":
        s = 0
        for j in reversed(range(n-ind)):
            dp2[j] = s
            s += dp[j]
            s %= mod
    else:
        s = 0
        for j in range(n):
            s += dp[j]
            dp2[j] = s
            s %= mod
    dp = dp2
print(dp[0])