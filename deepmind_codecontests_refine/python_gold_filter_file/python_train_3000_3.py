N, M = map(int, input().split())
A = list(map(int, input().split()))
weight = [0,2,5,5,4,5,6,3,7,6]
inf = float('inf')
dp = [-inf] * (N+1)
dp[0] = 0
for i in range(N+1):
    for a in A:
        if i + weight[a] < N+1:
            dp[i + weight[a]] = max(dp[i + weight[a]], dp[i]*10 + a)
print(dp[-1])
