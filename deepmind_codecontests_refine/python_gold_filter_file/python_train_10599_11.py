MOD = 10**9+7

N, K = map(int, input().split())
A = [tuple(map(int, input().split())) for _ in range(N)]

def power(base, exp, op=lambda x, y: x * y, ie=1):
    res = ie
    while exp:
        if exp & 1:
            res = op(res, base)
        base = op(base, base)
        exp >>= 1
    return res

matrix_id = [[i == j for j in range(N)] for i in range(N)]

def matrix_mul(A, B):
    res = [[0 for j in range(N)] for i in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                res[i][j] += A[i][k] * B[k][j]
                res[i][j] %= MOD
    return res

P = power(A, K, matrix_mul, matrix_id)

res = 0

for i in range(N):
    for j in range(N):
        res += P[i][j]
        res %= MOD

print(res)