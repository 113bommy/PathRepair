md = 10 ** 9 + 7
n = int(input())
s = input()
dp = [1] * n
for i in range(n - 1):
    if s[i] == "<":
        L = dp[0]
        for dpi in range(1, n - i - 1):
            dp[dpi] = L = (dp[dpi] + L) % md
        dp = dp[:-1]
    else:
        R = dp[-1]
        for dpi in range(n - i - 2, 0, -1):
            dp[dpi] = R = (dp[dpi] + R) % md
        dp = dp[1:]
print(dp[0])
