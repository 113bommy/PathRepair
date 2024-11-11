H,N = map(int,(input().split()))
dp = [10**9]*(H+1)
dp[0] = 0

A = [list(map(int,(input().split()))) for _ in range(N)]

for i in range(H+1):
    for j,k in A:
        next = min(H,i+j)
        dp[next] = min(dp[next],dp[i]+k)

print(dp[H])