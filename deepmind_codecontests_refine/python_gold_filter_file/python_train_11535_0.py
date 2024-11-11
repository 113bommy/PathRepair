R, C = map(int, input().split())

A = [list(map(int, input().split())) for _ in range(R)]
B = [list(map(int, input().split())) for _ in range(R)]

dp = [0] * C
dp[0] = s = 1 << 6400

for row_a, row_b in zip(A, B):
    for i, (a, b) in enumerate(zip(row_a, row_b)):
        d = abs(a - b)
        if i > 0:
            dp[i] |= dp[i - 1]
        dp[i] = (dp[i] << d) | (dp[i] >> d)

g = dp[-1]
for i in range(6401):
    if g & (s << i) or g & (s >> i):
        print(i)
        quit()
