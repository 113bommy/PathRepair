INF = 10 ** 12

N = int(input())
a = [list(map(int, input().split())) for _ in range(N)]

for i in range(N):
    for j in range(N):
        for k in range(N):
            if a[i][j] > a[i][k] + a[k][j]:
                print(-1)
                exit()

res = 0
for i in range(N):
    for j in range(i + 1, N):
        for k in range(N):
            if i != k and j != k and a[i][j] == a[i][k] + a[k][j]:
                break
        else:
            res += a[i][j]

print(res)
