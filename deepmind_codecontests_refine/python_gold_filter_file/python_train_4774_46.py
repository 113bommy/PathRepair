N,Ma,Mb = map(int,input().split())
ABC = [list(map(int,input().split())) for _ in [0]*N]
INFTY = 10**8
dp = [[[INFTY]*10*(N+1) for _ in [0]*10*(N+1)] for _ in [0]*(N+1)]
dp[0][0][0] = 0
for i in range(1,N+1):
    a,b,c = ABC[i-1]
    for j in range(10*(N+1)):
        for k in range(10*(N+1)):
            dp[i][j][k] = dp[i-1][j][k]
            if j-a>=0 and k-b>=0:
                dp[i][j][k] = min(dp[i][j][k],dp[i-1][j-a][k-b]+c)
ans = min(dp[-1][Ma*k][Mb*k] for k in range(1,(10*(N+1)-1)//max(Ma,Mb)+1))
if ans == INFTY : ans = -1
print(ans)