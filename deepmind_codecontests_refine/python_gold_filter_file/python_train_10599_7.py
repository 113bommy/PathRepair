n, kk = map(int, input().split())
AA = [list(map(int, input().split())) for _ in range(n)]
mod = 10 ** 9 + 7

# nxnの行列積


def matrix_product(A, B):
    res = [[0] * n for _ in range(n)]
    for i in range(n):
        for k in range(n):
            for j in range(n):
                res[i][j] += A[i][k] * B[k][j]
                res[i][j] %= mod
    return res


def matrix_exponents(A, t):
    res = [[0] * n for _ in range(n)]
    for i in range(n):
        res[i][i] = 1

    while t:
        if t & 1 == 1:
            res = matrix_product(res, A)
        A = matrix_product(A, A)
        t //= 2
    return res


temp = matrix_exponents(AA, kk)


ans = 0
for i in range(n):
    for j in range(n):
        ans += temp[i][j]
        ans %= mod
print(ans)
