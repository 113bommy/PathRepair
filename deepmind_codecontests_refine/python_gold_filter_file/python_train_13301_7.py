R, C, K = map(int, input().split())

V = [[0]*(C+1) for _ in range(R+1)]
for _ in range(K):
    r, c, v = map(int, input().split())
    V[r][c] = v

max_p = [0]*(C+1)
for i in range(R+1):
    now0 = [0]*(C+1)
    now1 = [0]*(C+1)
    now2 = [0]*(C+1)
    now3 = [0]*(C+1)
    for j in range(C+1):
        v = V[i][j]
        la = lb = 0
        if j > 0:
            la = now0[j-1]
            lb = now1[j-1]
            now2[j] = max(now2[j], now2[j-1], lb + v)
            now3[j] = max(now3[j], now3[j-1], now2[j-1] + v)
        if i > 0:
            now0[j] = max(now0[j], max_p[j], la)
            now1[j] = max(now1[j], max_p[j] + v, la + v, lb)
        max_p[j] = max(now0[j], now1[j], now2[j], now3[j])

print(max(now0[C], now1[C], now2[C], now3[C]))
