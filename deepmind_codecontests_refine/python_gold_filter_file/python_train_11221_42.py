H,N = map(int,input().split())

dp = [float("INF")]*(H+1)
dp[0] = 0
for i in range(N):
    a,b= map(int,input().split())
    for j in range(1,H+1):
        dp[j] = min(dp[j],dp[max((j-a),0)]+b)

print(dp[-1])