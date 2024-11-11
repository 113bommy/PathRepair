import itertools

N, C = map(int, input().split())
D = [tuple(map(int, input().split())) for _ in range(C)]
L = [tuple(map(int, input().split())) for _ in range(N)]

lst = [[0] * 3 for _ in range(C)]
for y in range(N):
    for x in range(N):
        for c in range(C):
            lst[c][(x + y) % 3] += D[L[y][x] - 1][c]

ans = float('inf')
for t in itertools.permutations(range(C), 3):
    ans = min(ans, sum(lst[t[i]][i] for i in range(3)))
print(ans)
