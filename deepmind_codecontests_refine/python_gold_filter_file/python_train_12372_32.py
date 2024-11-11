N=int(input())
A=[list(map(int,input().split())) for i in range(N)]

ans = 0
for i in range(N):
    for j in range(i + 1, N):
        ok = True
        for k in range(N):
            if i == k or j == k:
                continue
            if A[i][j] > A[i][k] + A[k][j]:
                print(-1)
                exit(0)
            elif A[i][j] == A[i][k] + A[k][j]:
                ok = False
        if ok:
            ans += A[i][j]

print(ans)
