mod = 10**9+7


def mat_mul(A, B):
    # A,Bは正方行列とする
    C = [[0]*N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            C[i][j] = sum(A[i][k] * B[k][j] for k in range(N)) % mod
    return C


def matpow(A, n):
    B = [[0]*N for _ in range(N)]
    for i in range(N):
        B[i][i] = 1
    while n > 0:
        if n & 1:
            B = mat_mul(A, B)
        A = mat_mul(A, A)
        n //= 2
    return B


if __name__ == "__main__":
    N, K = map(int, input().split())
    A = [list(map(int, input().split())) for _ in range(N)]
    A = matpow(A, K)
    ans = 0
    for a in A:
        ans = (ans + sum(a)) % mod
    print(ans)
