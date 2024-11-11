import sys
sys.setrecursionlimit(10 ** 5)

n, u, v = map(int, input().split())
u -= 1
v -= 1
es = [[] for i in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    es[a-1].append(b-1)
    es[b-1].append(a-1)

def dfs(v, dist, p=-1, d=0):
    dist[v] = d
    for nv in es[v]:
        if nv == p:
            continue
        dfs(nv, dist, v, d+1)

def calc_dist(x):
    dist = [-1] * n
    dfs(x, dist)
    return dist

dist_t = calc_dist(u)
dist_a = calc_dist(v)

mx = 0
for i in range(n):
    if dist_t[i] < dist_a[i]:
        mx = max(mx, dist_a[i])

ans = mx - 1
print(ans)