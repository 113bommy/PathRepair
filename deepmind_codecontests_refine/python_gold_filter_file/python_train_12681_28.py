s = input()
t = input()
m = len(s)
n = len(t)
dp = [[0]*(n+1) for _ in range(m+1)]
for i in range(1,m+1):
    for j in range(1,n+1):
        x = s[i-1]
        y = t[j-1]
        if x == y:
            dp[i][j] = dp[i-1][j-1]+1
        else:
            dp[i][j] = max(dp[i-1][j],dp[i][j-1])
res = ""
while n != 0 and m != 0:
    if dp[m][n] == dp[m-1][n]:
        m -= 1
    elif dp[m][n] == dp[m][n-1]:
        n -= 1
    else:
        n -= 1
        m -= 1
        res = s[m] + res
print(res)