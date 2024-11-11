n = int(input())
#v = [[] for i in range(n)]
edges = []
for i in range(n - 1):
    e = tuple(map(int, input().split()))
    edges.append(e)
c = list(map(int, input().split()))

edges_dc = []
for e in edges:
    if c[e[0] - 1] != c[e[1] - 1]:
        edges_dc.append(e)

roots = set()
for e in edges_dc:
    x = set(e)
    if len(roots) == 1:
        if len(x.intersection(roots)) == 0:
            print('NO')
            break
    elif len(roots) == 0:
        roots = x
    elif len(roots) == 2:
        roots = x.intersection(roots)
        if len(roots) == 0:
            print('NO')
            break
else:
    print('YES')
    if len(roots) == 0:
        roots.add(1)
    print(roots.pop())