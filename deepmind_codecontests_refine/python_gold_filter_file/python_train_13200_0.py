n, a, b, MOD = map(int, input().split())


def mult(A, B, N):
    C = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                C[i][j] += A[i][k] * B[k][j]
            C[i][j] %= MOD
    return C


def mat_power(A, N, n):
    if n == 0:
        res = [[0] * N for _ in range(N)]
        for i in range(N):
            res[i][i] = 1
        return res
    X = mat_power(A, N, n // 2)
    X = mult(X, X, N)
    return mult(A, X, N) if n & 1 else X


li = [0]
t = 1
while li[-1] < n:
    p = pow(10, t)
    l, r = li[-1] - 1, n
    while r - l > 1:
        m = (l + r) // 2
        if a + b * m < p:
            l = m
        else:
            r = m
    li.append(r)
    t += 1
ans = 0
for i in range(len(li) - 1):
    p = pow(10, i + 1)
    t = li[i + 1] - li[i]
    am = [[p, 1, 0], [0, 1, 1], [0, 0, 1]]
    mat = mat_power(am, 3, t)
    ans *= pow(10, t * (i + 1), MOD)
    ans += mat[0][1] * ((a + b * li[i])) + mat[0][2] * b
    ans %= MOD
print(ans)
