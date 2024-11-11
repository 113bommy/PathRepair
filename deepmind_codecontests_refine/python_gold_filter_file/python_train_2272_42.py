N, C = map(int, input().split())
D = [tuple(map(int, input().split())) for _ in range(C)]
color = [tuple(map(int, input().split())) for _ in range(N)]

wrongness = [[0, 0, 0] for _ in range(C)]

for c in range(C):
    for i in range(N):
        for j in range(N):
            wrongness[c][(i + j) % 3] += D[color[i][j] - 1][c]

ans = 10**18

for c1 in range(C):
    for c2 in range(C):
        for c3 in range(C):
            if c1 == c2 or c2 == c3 or c3 == c1:
                continue
            ans = min(ans, wrongness[c1][0] + wrongness[c2][1] + wrongness[c3][2])

print(ans)