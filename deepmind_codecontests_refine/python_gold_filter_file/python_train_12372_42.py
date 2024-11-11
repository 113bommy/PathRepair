N = int(input())
d = [list(map(int, input().split())) for _ in range(N)]

check = [[1] * N for _ in range(N)]

for i in range(N):
    for j in range(N):
        if i == j:
            continue
        for k in range(N):
            if i == k or j == k:
                pass
            else:                    
                if d[i][j] > d[i][k] + d[k][j]:
                    print (-1)
                    exit()
                elif d[i][j] == d[i][k] + d[k][j]:
                    check[i][j] = 0

ans = 0
for i in range(N):
    for j in range(N):
        ans += d[i][j] * check[i][j]

print (ans // 2)    