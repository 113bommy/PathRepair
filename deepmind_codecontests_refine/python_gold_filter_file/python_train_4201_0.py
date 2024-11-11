s = input()
dp = [0]*(len(s)+1)
for i in range(1, len(s)+1):
    dp[i] = dp[i-1] + s[i-1].islower()

ans = min(dp[-1], len(s) - dp[-1])
for i in range(len(s)):
    ltr = dp[-1] - dp[i+1]
    ltl = dp[i+1]
    ans = min(ans, ltl + len(s) - i - 1 - ltr)

print(ans)