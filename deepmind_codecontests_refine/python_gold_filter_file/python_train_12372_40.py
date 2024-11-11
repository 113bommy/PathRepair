N = int(input())
A = [[0] for i in range(N)]
for i in range(N):
    A[i] = list(map(int, input().split()))

#for i in range(N):
#    A[i][i] = float("INF")

f = 0
r = [[1] * N for i in range(N)]

for k in range(N):
    for i in range(N):
        for j in range(N):
            if A[i][j] > A[i][k] + A[k][j]:
                f = 1
            elif A[i][j] == A[i][k] + A[k][j] and i != k and j != k:
                r[i][j] = 0

if f == 1:
    print("-1")
else:
    #print(r)
    ans = 0
    for i in range(N):
        for j in range(i+1, N):
            ans += A[i][j] * r[i][j]

    print(ans)