N,K = map(int, input().split())
h = list(map(int, input().split()))

dp = [0] + [1000000000000]*(N-1)

for i in range(1,N):
    for j in range(max(i-K,0),i):
        dp[i] = min(dp[i],dp[j]+abs(h[i]-h[j]))

print(dp[-1])
