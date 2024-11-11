N, K = map(int,input().split())
h = list(map(int, input().split()))

dp = [1e+09]*N
dp[0] = 0
for i in range(1,N):
  for j in range(1,K+1):
    if i >= j: dp[i] = min(dp[i],dp[i-j]+abs(h[i] - h[i-j]))
print(int(dp[-1]))
