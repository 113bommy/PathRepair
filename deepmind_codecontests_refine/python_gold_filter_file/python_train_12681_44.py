s = input()
t = input()
S = len(s)
T = len(t)
dp = [[0 for _ in range(T+1)] for _ in range(S+1)]
for i in range(S):
    for j in range(T):
        if s[i] == t[j]:
            dp[i + 1][j + 1] = dp[i][j] + 1
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1])
ans = ''
i = S
j = T
while i > 0 and j > 0:
    if dp[i][j] == dp[i-1][j]:
        i -= 1
    elif dp[i][j] == dp[i][j-1]:
        j -= 1
    else:
        ans = s[i-1] + ans
        i -= 1
        j -= 1
print(ans)