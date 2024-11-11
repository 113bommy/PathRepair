N, C = map(int, input().split())
D = [list(map(int, input().split())) for _ in range(C)]
G = [list(map(int, input().split())) for _ in range(N)]

cost = [[0]*C for _ in range(3)]
for i in range(C):
    for a in range(N):
        for b in range(N):
            cost[(a+b)%3][i] += D[G[a][b]-1][i]

ans = 10**10
for i in range(C):
    for j in range(C):
        for k in range(C):
            if i == j or j == k or k == i:
                pass
            else:
                ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k])

print(ans)
