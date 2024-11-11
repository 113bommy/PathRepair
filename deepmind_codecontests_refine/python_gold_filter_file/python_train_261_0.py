n, m = map(int, input().split())
adj = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    adj[a].append(b)
    adj[b].append(a)

colour = [None] * n
bad = False

for i in range(n):
    if colour[i] is None:
        todo = [(i, True)]
        while todo:
            xi, xc = todo.pop()
            if colour[xi] is not None:
                if colour[xi] == xc:
                    continue
                else:
                    bad = True
                    break
            colour[xi] = xc
            for neighbour in adj[xi]:
                todo.append((neighbour, not xc))
    if bad:
        break

if bad:
    print(-1)
else:
    f = []
    t = []
    for i in range(n):
        if colour[i]:
            t.append(i+1)
        else:
            f.append(i+1)
    print(len(f))
    print(" ".join(map(str, f)))

    print(len(t))
    print(" ".join(map(str, t)))
