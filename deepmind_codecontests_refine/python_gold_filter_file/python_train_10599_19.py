mod = 10**9 + 7

N, K = map(int,input().split())
A = [list(map(int,input().split())) for _ in range(N)]

def dot(X, Y):
    x = len(X)
    y = len(Y[0])
    z = len(Y)
    C = [[0] * y for _ in range(x)]
    for i in range(x):
        for j in range(y):
            for k in range(z):
                C[i][j] += X[i][k] * Y[k][j]
                C[i][j] %= mod
    return C

B = [[0] * N for _ in range(N)]
for k in range(N):
    B[k][k] = 1

while K > 0:
    if K & 1:
        B = dot(B, A)
    A = dot(A, A)
    K >>= 1

ans = 0
for i in range(N):
    for j in range(N):
        ans += B[i][j]
        ans %= mod

print(ans)