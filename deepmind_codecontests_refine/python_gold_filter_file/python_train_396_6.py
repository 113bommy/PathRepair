S = input()
N = len(S)
INF = float('inf')
dp = [INF] * N
dp[0] = 0
dp2 = {}
dp2[0] = 0
bits = [1 << i for i in range(26)]
x = 0

for i in range(N):
    x = x ^ bits[ord(S[i]) - ord('a')]
    tmp = INF
    if x not in dp2:
        dp2[x] = INF
    tmp = min(tmp, dp2[x])

    for b in bits:
        k = x ^ b
        if k not in dp2:
            dp2[k] = INF
        tmp = min(tmp, dp2[k])

    dp2[x] = min(dp2[x], tmp + 1)
    dp[i] = tmp + 1

print(dp[N - 1])