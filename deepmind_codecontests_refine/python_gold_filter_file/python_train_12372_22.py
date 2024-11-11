V = int(input())
A = [list(map(int, input().split())) for _ in range(V)]

ret = 0
for i in range(V):
    for j in range(i+1, V):
        f = True
        for k in range(V):
            if i == k or j == k:
                continue
            if A[i][j] > A[i][k] + A[k][j]:
                print(-1)
                exit()
            elif A[i][j] == A[i][k] + A[k][j]:
                f = False
        if f:
            ret += A[i][j]

print(ret)
