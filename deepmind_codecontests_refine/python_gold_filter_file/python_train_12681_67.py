S = input()
T = input()
N = len(S)
M = len(T)
dp = [[0] * (M+1) for _ in range(N+1)]
for i in range(1,N+1):
    for k in range(1,M+1):
        if S[i-1] == T[k-1]:
            dp[i][k] = dp[i-1][k-1] + 1
        else:
            dp[i][k] = max(dp[i-1][k],dp[i][k-1])
ans = ''
x = N
y = M
while x > 0 and y > 0:
    if dp[x][y] == dp[x-1][y]:
        x -= 1
    elif dp[x][y] == dp[x][y-1]:
        y -= 1
    else:
        x -= 1
        y -= 1
        ans += S[x]
print(ans[::-1])