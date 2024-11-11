from sys import stdin


def solve():
    s = str(input())
    if len(s) < 3: return 0
    t = 'QAQ'
    dp = [0]*(len(t) + 1)
    dp[0] = 1
    for i in range(len(s)):
        for j in range(len(t)):
            # print(dp, s[i], t[j])
            if s[i] == t[j]:
                dp[j+1] += dp[j]
    # print(dp)
    return dp[len(t)]

print(solve())