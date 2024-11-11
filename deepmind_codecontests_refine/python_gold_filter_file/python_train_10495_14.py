import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**7)
h, w = map(int, input().split())
n = h*w
fld = ''.join([input().rstrip()for _ in range(h)])
edges = [[]for _ in range(n)]


def to_v(i, j):
    return i*w+j


for i in range(h):
    for j in range(w):
        v = to_v(i, j)
        dirc = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        for di, dj in dirc:
            x, y = i+di, j+dj
            if x < 0 or h <= x or y < 0 or w <= y:
                continue
            v2 = to_v(x, y)
            if fld[v] != fld[v2]:
                edges[v].append(v2)
                edges[v2].append(v)


def dfs(v, c=0):
    if visited[v]:
        return
    visited[v] = 1
    cnt[c] += 1
    for v2 in edges[v]:
        dfs(v2, c ^ 1)


visited = [0]*n
ans = 0
for v in range(n):
    if visited[v]:
        continue
    cnt = [0, 0]
    dfs(v)
    ans += cnt[0]*cnt[1]
print(ans)
