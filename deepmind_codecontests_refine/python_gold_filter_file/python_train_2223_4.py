def dfs(v):
    global marked, g
    marked[v]  = True
    for nv in g[v]:
        if not marked[nv]:
            dfs(nv)
n = int(input())
g = [[] for _ in range(n+1)]
x  = [0 for _ in range(n+1)]
y  = [0 for _ in range(n+1)]
marked = [False for _ in range(n+1)]
for i in range(1, n+1):
    x[i], y[i] = map(int, input().split())
    for j in range(1, i):
        if (x[j] == x[i] or y[j] == y[i]):
            g[i].append(j)
            g[j].append(i)
cnt = 0
for i in range(1, n+1):
    if not marked[i]:
        dfs(i)
        cnt+=1
print(cnt-1)
