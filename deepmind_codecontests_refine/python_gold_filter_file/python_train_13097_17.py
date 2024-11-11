N = int(input())
dp = [0,0,0]
for _ in range(N):
    a, b, c = map(int, input().split())
    ndp = [0,0,0]
    ndp[0] = max(dp[1], dp[2]) + a
    ndp[1] = max(dp[0], dp[2]) + b
    ndp[2] = max(dp[0], dp[1]) + c
    dp = ndp
print(max(dp))
