import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n, m = map(int, input().split())
g = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

if m % 2 == 1:
    print(-1)
    exit()

ans = []

depth = [-1] * n
deg = [0] * n
def dfs(v, pr):
    for nv in g[v]:
        if nv == pr:
            continue
        if depth[nv] != -1:
            if depth[nv] < depth[v]:
                ans.append((v, nv))
                deg[v] += 1
        else:
            depth[nv] = depth[v] + 1
            dfs(nv, v)
            if deg[nv] % 2 == 0:
                ans.append((v, nv))
                deg[v] += 1
            else:
                ans.append((nv, v))
                deg[nv] += 1

depth[0] = 0
dfs(0, -1)

for i, j in ans:
    print(i + 1, j + 1)




