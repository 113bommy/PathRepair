from itertools import *
N, C = map(int, input().split())
D = [list(map(int, input().split())) for _ in [0]*C]
c = [list(map(int, input().split())) for _ in [0]*N]
tri = [[] for _ in [0]*3]
for i in range(1, N+1):
    for j in range(1, N+1):
        tri[(i+j) % 3] += [c[i-1][j-1] - 1]
incom = [[0]*C for _ in [0]*3]
for i in range(3):
    for color in range(C):
        incom[i][color] = sum(D[x][color] for x in tri[i])
ans = 1<<30
for p in permutations(range(C), 3):
    t = sum(incom[x][y]for x,y in enumerate(p))
    if t < ans: ans = t
print(ans)