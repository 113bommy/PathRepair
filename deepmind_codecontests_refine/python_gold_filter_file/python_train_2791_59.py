N,K = map(int,input().split())
h = list(map(int,input().split()))
dp = [0] * N
dp[0] = 0
for i in range(1,N):
    dp[i] = min([dp[i-j-1] + abs(h[i]-h[i-j-1]) for j in range(min(i,K))])
 
print(dp[-1])