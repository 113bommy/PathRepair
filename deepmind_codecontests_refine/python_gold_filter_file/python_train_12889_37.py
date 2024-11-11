N,W=map(int,input().split(' '))
w,v=[0]*N,[0]*N
for i in range(N):
    w[i],v[i]=map(int,input().split(' '))
dp=[[0]+[W+1]*(sum(v)+1) for _ in range(N+1)]
for i in range(N):
    for nv in range(sum(v),0,-1):
        if nv<v[i]:
            dp[i+1][nv]=min(dp[i][nv],dp[i+1][nv+1])
        else:
            dp[i+1][nv]=min(dp[i][nv],dp[i][nv-v[i]]+w[i])

print(dp[N].index(W+1)-1)