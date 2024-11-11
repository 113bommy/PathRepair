N,K = map(int,input().split())

h = [int(x) for x in input().split()]

dp = [10**9]*N
dp[0] = 0

for i in range(1,N):
    for j in range(1,min(i+1,K+1)):
        dp[i] = min(dp[i],dp[i-j]+abs(h[i]-h[i-j]))

print(dp[N-1])