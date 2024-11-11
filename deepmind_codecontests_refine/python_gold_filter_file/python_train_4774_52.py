INF = float('inf')
N,Ma,Mb = map(int,input().split())
abc = [list(map(int,input().split())) for _ in range(N)]
dp = [[[INF]*(10*N+11) for _ in range(10*N+11)] for _ in range(N+1)]
dp[0][0][0] = 0

for i in range(N):
    for a1 in range(10*N+1):
        for b1 in range(10*N+1):
            a,b,c = abc[i]
            dp[i+1][a1][b1] = min(dp[i][a1][b1],dp[i][a1-a][b1-b]+c)

ans = INF
for a1 in range(1,10*N+1):
    for b1 in range(1,10*N+1):
        if a1*Mb == b1*Ma:
            ans = min(ans,dp[N][a1][b1])

if ans == INF:
    ans = -1

print(ans)