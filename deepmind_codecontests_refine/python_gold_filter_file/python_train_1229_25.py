N, K, *A = map(int, open(0).read().split())

dp = [False] * (K + 1)
for i in range(1, K + 1):
    for a in A:
        if i - a >= 0:
            dp[i] |= not dp[i - a]

if dp[K]:
    print("First")
else:
    print("Second")