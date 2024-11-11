n,ma,mb = map(int,input().split())

INF = 10**4
dp = [[[INF] * (n*10+1) for _ in range(n*10+1)] for _ in range(n+1)]
dp[0][0][0] = 0

for i in range(n):
    a,b,c = map(int,input().split())
    for ai in range(i*10+11):
        for bi in range(i*10+11):
            if ai>=a and bi>=b:
                tmp = dp[i][ai-a][bi-b] + c
            else:
                tmp = INF
            dp[i+1][ai][bi] = min(dp[i][ai][bi], tmp)

ans = min(dp[n][ma*i][mb*i] for i in range(1,n*10//max(ma,mb)+1) )
if ans == INF: ans = -1
    
print(ans)