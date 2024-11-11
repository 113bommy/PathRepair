def inpl(): return list(map(int, input().split()))

H, W = inpl()
A = [inpl() for _ in range(H)]
B = [inpl() for _ in range(H)]

DP = [[0 for _ in range(W+1)] for _ in range(H+1)]
DP[0][0] = 1 << 12800

for h in range(H):
    for w in range(W):
        d = abs(A[h][w] - B[h][w])
        DP[h+1][w] |= DP[h][w] >> d
        DP[h+1][w] |= DP[h][w] << d
        DP[h][w+1] |= DP[h][w] >> d
        DP[h][w+1] |= DP[h][w] << d
l = 1 << 12800
r = 1 << 12800
for i in range(12801):
    if (DP[-1][-2]& l) | (DP[-1][-2] & r):
        print(i)
        break
    l = l << 1
    r = r >> 1