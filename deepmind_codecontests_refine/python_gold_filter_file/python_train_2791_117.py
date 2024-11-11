# 貰うDP
N,K=map(int,input().split())
h=list(map(int,input().split()))
INF=10**9
dp=[INF]*(N)
dp[0]=0

for n in range(1,N):
    dp[n]=min([dp[k] + abs(h[n] - h[k]) for k in range(max(0,n-K), n)])
print(dp[N-1])