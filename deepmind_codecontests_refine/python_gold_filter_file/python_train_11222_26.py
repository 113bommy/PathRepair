N = int(input())
H = list(map(int, input().split()))

dp = [0]*N

for i in range(1, N):
    if H[i-1] >= H[i]:
        dp[i] = dp[i-1] + 1
print(max(dp))

