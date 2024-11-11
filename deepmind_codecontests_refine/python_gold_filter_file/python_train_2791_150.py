N,K = map(int,input().split())
h = list(map(int,input().split()))

dp = [0]*N
for i in range(1,N):
    dp[i] = min([dp[i-j]+abs(h[i]-h[i-j]) for j in range(1,min(i,K)+1)])
print(dp[-1])