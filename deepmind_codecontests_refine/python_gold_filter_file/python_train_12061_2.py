N,W = map(int, input().split())
wvs = []
for i in range(N):
    w,v = map(int, input().split())
    wvs.append((w,v))
# dp : n個入っていて、合計がwのときの最大値
w0 = wvs[0][0]
dp = [[[-1]*(330) for i in range(110)] for k in range(110)]
dp[0][0][0] = 0
for i in range(N):
    w, v = wvs[i]
    dw = w-w0
    for j in range(i+1):
        for k in range(310):
            # if k - dw >= 0:
            # if dp[i][j][j] == -1:continue
            dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k])
            dp[i+1][j+1][k+dw] = max(dp[i][j][k]+v, dp[i+1][j+1][k+dw])

d = dp[N]
ans = 0
for j in range(N+1):
    if W-j*w0 >= 0:
        a = max(d[j][:W-j*w0+1])
        ans = max(ans, a)
print(ans)