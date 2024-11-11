N, K = map(int, input().split())
H = list(map(int, input().split()))

dp = [0 for _ in range(N)]

for i in range(1,N): #0 <= i < N
    dp[i] = min([dp[i-k] + abs(H[i]-H[i-k]) for k in range(1, min(i, K)+1)])

print(dp[-1])