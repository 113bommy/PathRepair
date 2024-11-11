N,W = map(int, input().split())
ws = []
vs = []
for i in range(N):
    w,v = map(int, input().split())
    ws.append(w)
    vs.append(v)
ws_m = [w-ws[0] for w in ws]

"""
i番目まで見て、n個選んでいて、重さがwのときのvの最大値
ただし、wはN個選んだときにW-N*[w[0]]となっているので、そこをmaxとする
dp[i][n][w] 
"""
dp = [[-1]*(3*N+1) for i in range(N+1)]
dp[0][0] = 0
for i,(w,v)  in enumerate(zip(ws_m,vs)):    
    dp[i+1][:] = dp[i][:]
    for j in range(len(dp[i])):
        if dp[i][j] == -1:continue
        dp[i+1][j+w] = max(dp[i][j]+v, dp[i][j+w])
    # print(dp)

# print(dp[N][W-N*ws_m[0]])

dp = [[[-1]*(3*N+1) for i in range(N+1)] for j in range(N+1)]
dp[0][0][0] = 0
for i,(w,v)  in enumerate(zip(ws_m,vs)):
    # print(i,w,v)
    for n in range(N):
        # dp[i+1][n][:] = dp[i][n][:]
        for j in range(N):
            if dp[i][n][j] == -1:continue
            if dp[i][n][j]+v >= dp[i][n][j+w]:
                # print("aa",i,n,j,v)
                dp[i+1][n+1][j+w] = dp[i][n][j] + v
            else:
                dp[i+1][n][j+w] = dp[i][n][j+w]
            dp[i+1][n][j] = max(dp[i+1][n][j], dp[i][n][j])
    # print(dp[i])

# for i in range(N+1):
    # print("i個選んだやつ",dp[N][i])
anss = dp[N]
a = 0
for i,ans in enumerate(anss):
    w = W - i*ws[0]
    if w >= 0:
        a = max(a,max(ans[:w+1]))
print(a)   
