N, K = map(int, input().split())
*A, = map(int, input().split())
dp = [False] * (K+1)
for i in range(1, K+1):
    for a in A:
        if i - a < 0: break
        dp[i] |= not dp[i-a]
print('First' if dp[K] else 'Second')