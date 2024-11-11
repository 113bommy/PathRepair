def pow(mat, k, mod):
    n = len(mat)
    if k == 0:
        return [[1 if i == j else 0 for i in range(n)] for j in range(n)]
    if k % 2 == 0:
        sqrt_mat = pow(mat, k // 2, mod)
        # calculate 'sqrt_mat * sqrt_mat'
        ret = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                v = 0
                for k in range(n):
                    v += sqrt_mat[i][k] * sqrt_mat[k][j]
                    v %= mod
                ret[i][j] = v
        return ret
    else:
        powmat = pow(mat, k - 1, mod)
        # calculate 'mat * powmat'
        ret = [[0 for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n):
                v = 0
                for k in range(n):
                    v += mat[i][k] * powmat[k][j]
                    v %= mod
                ret[i][j] = v
        return ret


def main():
    MOD = 10 ** 9 + 7
    N, K = list(map(int, input().split(' ')))
    A = [list(map(int, input().split(' '))) for _ in range(N)]
    D = pow(A, K, MOD)
    ans = 0
    for i in range(N):
        for j in range(N):
            ans += D[i][j]
            ans %= MOD
    print(ans)


if __name__ == '__main__':
    main()
