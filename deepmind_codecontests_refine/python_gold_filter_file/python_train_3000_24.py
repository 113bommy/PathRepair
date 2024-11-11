N, M = map(int, input().split())
A = list(map(int, input().split()))

dp = [-1] * (N+1)
need = [0, 2, 5, 5, 4, 5, 6, 3, 7, 6]
dp[0] = 0

for i in range(N+1):
    for j in A:
        if i + need[j] > N:
            continue
        dp[i+need[j]] = max(dp[i+need[j]], dp[i]*10+j)
print(dp[N])