from sys import *
f = lambda: map(int, stdin.readline().split())
n, m = f()
g = [[i] for i in range(n + 1)]
for j in range(m):
    u, v = f()
    g[u].append(v)
    g[v].append(u)
k = 'YES'
for t in g: t.sort()
for t in g:
    s = len(t)
    if s > 1 and not all(g[x] == t for x in t):
        k = 'NO'
        break
    for j in t: g[j] = []
print(k)