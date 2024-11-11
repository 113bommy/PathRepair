N,K = map(int,input().split())
stones = list(map(int,input().split()))
dp =[0] *N

for i in range(1,N):
    dp[i] = min(abs(stones[i] - stones[j]) + dp[j] for j in range(max(0, i - K), i))

print(dp[-1])
