X = input()
Y = input()

dp = [[0]*(len(Y)+1) for _ in [0]*(len(X)+1)]

for i, x in enumerate(X):
    i += 1
    for j, y in enumerate(Y):
        j += 1
        dp[i][j] = max(dp[i-1][j-1]+int(x == y),
                       dp[i-1][j], dp[i][j-1])

ans = []
cnt = dp[-1][-1]
x = y = -1
while cnt:
    while dp[x-1][y] == cnt:
        x -= 1
    while dp[x][y-1] == cnt:
        y -= 1
    ans.append(X[x])
    cnt -= 1
    x -= 1
    y -= 1
ans = ''.join(ans)[::-1]
print(ans)
