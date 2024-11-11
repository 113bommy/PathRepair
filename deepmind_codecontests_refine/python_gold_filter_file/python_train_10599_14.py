N, K = map(int, input().split())
A = [list(map(int, input().split())) for i in range(N)]
mod = 10**9+7

def matrixmul(A, B):
    n = len(A)
    C = []
    for i in range(n):
        c = []
        for j in range(n):
            num = 0
            for k in range(n):
                num = (A[i][k]*B[k][j] + num)%mod
            c.append(num)
        C.append(c)
    return C

now = [[1 if i == j else 0 for i in range(N)] for j in range(N)]        

while K:
    if K&1 == 1:
        now = matrixmul(now, A)
    K //= 2
    A = matrixmul(A, A)

ans = 0
for i in range(N):
    for j in range(N):
        ans = (now[i][j]+ans)%mod
print(ans)