MOD = 10 ** 9 + 7

N, K = map(int, input().split())

A = [list(map(int, input().split())) for _ in range(N)]

def mod_pow(matrix, n, mod): #行列累乗を求める
    # print (matrix)
    N = len(matrix[0])
    if n == 0:
        lst = [[1 if i == j else 0 for i in range(N)] for j in range(N)]
        return lst
    lst = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            for k in range(N):
                # print (i, j, k)
                lst[i][j] += matrix[i][k] * matrix[k][j]
            lst[i][j] %= mod
    res = mod_pow(lst, n // 2, mod)

    lst = [[0] * N for _ in range(N)]
    if n % 2 == 1:
        for i in range(N):
            for j in range(N):
                for k in range(N):
                    lst[i][j] += res[i][k] * matrix[k][j]
                lst[i][j] %= mod
        return lst
    return res 

matrix = mod_pow(A, K, MOD)
# print (matrix)

ans = 0
for i in range(N):
    for j in range(N):
        ans += matrix[i][j]
        ans %= MOD

ans %= MOD
print (ans)