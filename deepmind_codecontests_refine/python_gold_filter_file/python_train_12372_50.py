n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
B = [[1] * n for _ in range(n)]

for k in range(n):
    for i in range(n):
        for j in range(n):
            if k != i and k != j:
                if A[i][j] > A[i][k] + A[k][j]:
                    print(-1)
                    exit()
                elif A[i][j] == A[i][k] + A[k][j]:
                    B[i][j] = 0

ans = 0
for i in range(n):
    for j in range(i):
        if B[i][j]:
            ans += A[i][j]

print(ans)
