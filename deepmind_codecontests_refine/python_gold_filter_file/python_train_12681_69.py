s = input()
t = input()
n, m = len(s), len(t)
dp = [[0]*(m+1) for _ in range(n+1)]

for i in range(1, n+1):
    for j in range(1, m+1):
        if s[i-1] == t[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])

i, j = n, m

ans = []

while i > 0 and j > 0:
    if dp[i][j] == dp[i][j-1]:
        j -= 1
    elif dp[i][j] == dp[i-1][j]:
        i -= 1
    else:
        ans.append(s[i-1])
        i -= 1
        j -= 1

print("".join(reversed(ans)))