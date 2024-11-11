R, C, K = map(int, input().split())

V = [[0]*(C+1) for _ in range(R+1)]
for _ in range(K):
    r, c, v = map(int, input().split())
    V[r][c] = v

pre = [[0]*(3+1) for _ in range(C+1)]
for i in range(R+1):
    now = [[0]*(3+1) for _ in range(C+1)]
    for j in range(C+1):
        for k in range(3+1):
            if i-1 >= 0:
                now[j][0] = max(now[j][0], pre[j][k])
                now[j][1] = max(now[j][1], pre[j][k] + V[i][j])

            if j-1 >= 0:
                now[j][k] = max(now[j][k], now[j-1][k])
                if k-1 >= 0:
                    now[j][k] = max(now[j][k], now[j-1][k-1] + V[i][j])
    pre = now

print(max(now[C]))
