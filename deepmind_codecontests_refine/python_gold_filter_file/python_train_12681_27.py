s = input().strip()
t = input().strip()
ls = len(s)
lt = len(t)

dp = [[0]*(lt+1) for i in range(ls+1)]

for i in range(ls):
    for j in range(lt):
        v = dp[i][j]+1 if s[i] == t[j] else 0
        dp[i+1][j+1] = max([v, dp[i+1][j], dp[i][j+1]])

ans = ''
i, j = ls, lt
while i > 0 and j > 0:
    if dp[i][j] == dp[i-1][j]:
        i -= 1
    elif dp[i][j] == dp[i][j-1]:
        j -= 1
    else:
        ans = s[i-1]+ans
        i -= 1
        j -= 1

print(ans)