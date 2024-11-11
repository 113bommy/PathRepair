def bipartite(g):
    s = [(0, 1)]
    c = [0] * n
    while s:
        v, color = s.pop()
        c[v] = color
        for node in g[v]:
            if c[node] == c[v]:
                return False, None
            if c[node] == 0:
                s.append((node, -color))
    return True, c

n, m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    g[a - 1].append(b - 1)
    g[b - 1].append(a - 1)
b, colors = bipartite(g)
if b:
    x = colors.count(1)
    print(x * (n - x) - m)
else:
    print(n * (n - 1) // 2 - m)
