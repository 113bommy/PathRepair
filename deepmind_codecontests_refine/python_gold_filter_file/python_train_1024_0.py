N, M = map(int, input().split())

A = []
B = []
C = []

inf = 1*10**7
max_n = 110
G = [[inf] * max_n for i in range(max_n)]
for i in range(N):
    G[i][i] = 0


for i in range(M):
    a, b, c = map(int, input().split())
    A.append(a-1)
    B.append(b-1)
    C.append(c)
    G[A[i]][B[i]] = C[i]
    G[B[i]][A[i]] = C[i]

for k in range(N):
    for i in range(N):
        for j in range(N):
            G[i][j] = min(G[i][j], G[i][k] + G[k][j])

ans = 0
for i in range(M):
    if (G[A[i]][B[i]] < C[i]):
        ans += 1

# print(G)


print(ans)
