N, K = map(int, input().split())
H = [int(h) for h in input().split()]
dp = [0]*N
dp[1] = abs(H[1]-H[0])
for i in range(2, N):
    dp[i] = min([dp[i-j]+abs(H[i]-H[i-j]) for j in range(1, min(K, i)+1)])
print(dp[N-1])