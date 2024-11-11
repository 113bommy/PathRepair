s = input()
t = input()

x = len(s)
y = len(t)
dp = [[0]*(y+1) for _ in range(x+1)]

for i in range(x):
    for j in range(y):
        if s[i]==t[j]:
            dp[i+1][j+1] = dp[i][j] + 1
        else:
            dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1])

res = ""
while x>0 and y>0:
    if dp[x][y] == dp[x-1][y]:
        x -= 1
    elif dp[x][y] == dp[x][y-1]:
        y -= 1
    else:
        res = s[x-1] + res
        x -= 1
        y -= 1
print(res)