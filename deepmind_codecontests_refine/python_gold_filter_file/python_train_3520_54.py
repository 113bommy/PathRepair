N = int(input())
A = list(map(int, input().split()))
dp = [[0] * (N + 1) for _ in range(N+ 1)]

accum = [0] * (N + 1)
for i in range(N):
    accum[i + 1] = accum[i] + A[i]

for m in range(1, N+1):
    for l in range(N):
        if m == 1:
            dp[l][l + m] = 0
        else:
            if l + m < N + 1:
                r = l + m
                dp[l][r] = min([dp[l][l+k] + dp[l+k][r] for k in range(1, m)]) + accum[r] - accum[l]

print(dp[0][N])