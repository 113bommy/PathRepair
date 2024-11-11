n, m, l = map(int, input().split())
A = [list(map(int, input().split())) for i in range(n)]
B = [list(map(int, input().split())) for i in range(m)]

C = [[0] * l for i in range(n)]

for i in range(n):
    for j in range(l):
        C[i][j] = str(sum(A[i][k] * B[k][j] for k in range(m)))

for i in range(n):
    print(' '.join(C[i]))