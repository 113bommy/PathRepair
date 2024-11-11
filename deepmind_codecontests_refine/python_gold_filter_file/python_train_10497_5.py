n, k = map(int, input().split())
B = [[0]*k for i in range(k)]
W = [[0]*k for i in range(k)]
for i in range(n):
    x, y, c = input().split(); x = int(x); y = int(y)
    x %= 2*k; y %= 2*k
    if (k <= x) == (k <= y):
        (B if c == 'B' else W)[y%k][x%k] += 1
    else:
        (W if c == 'B' else B)[y%k][x%k] += 1
def calc(M, n):
    D = [[0]*(n+1) for i in range(n+1)]
    for i in range(1, n+1):
        tmp = 0
        for j in range(1, n+1):
            tmp += M[i-1][j-1]
            D[i][j] = tmp + D[i-1][j]
    return D

# [a, c) * [b, d)
def su(D, a, b, c, d):
    return D[d][c] - D[d][a] - D[b][c] + D[b][a]

DB = calc(B, k)
DW = calc(W, k)
ans = 0
for i in range(k):
    for j in range(k):
        ans = max(ans, su(DB, 0, 0, i, j) + su(DB, i, j, k, k) + su(DW, i, 0, k, j) + su(DW, 0, j, i, k))
        ans = max(ans, su(DW, 0, 0, i, j) + su(DW, i, j, k, k) + su(DB, i, 0, k, j) + su(DB, 0, j, i, k))
print(ans)
