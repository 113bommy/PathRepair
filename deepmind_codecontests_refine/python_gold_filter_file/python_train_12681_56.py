s = " " + input().strip()
t = " " + input().strip()
LS, LT = len(s), len(t)
dp = [[0]*LT for _ in range(LS)]
for i in range(1, LS):
    for j in range(1, LT):
        if s[i] == t[j]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
a, b = (LS-1, LT-1)
r = ""
while a > 0 and b > 0:
    if s[a] == t[b]:
        r+=s[a]
        a, b = a-1, b-1
    elif dp[a][b] == dp[a-1][b]:
        a -= 1
    else:
        b -= 1

print(r[::-1])
