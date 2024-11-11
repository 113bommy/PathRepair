import sys
sys.setrecursionlimit(10 ** 6)

N, M = map(int, input().split())
XYZ = []
for _ in range(M):
    XYZ.append(tuple(map(int, input().split())))

G = [[] for _ in range(N + 1)]
for el in XYZ:
    x, y, z = el
    G[x].append(y)
    G[y].append(x)

seen=[False] * (N + 1)
def dfs(parent):
    seen[parent] = True
    for child in G[parent]:
        if seen[child] == False:
            dfs(child)

cnt = 0
for start in range(1, N + 1):
    if seen[start] == False:
        dfs(start)
        cnt += 1
print(cnt)
