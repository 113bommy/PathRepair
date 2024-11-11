import sys
readline = sys.stdin.readline

V, E = map(int, readline().split())
inf = 10**10
vertices = [[inf if i!=j else 0 for j in range(V)] for i in range(V)]

for _ in [None]*E:
    s, t, d = map(int, readline().split())
    vertices[s][t] = d

for k in range(V):
    for i in range(V):
        for j in range(V):
            c1, c2, c3 = vertices[i][j], vertices[i][k], vertices[k][j]
            if c2 != inf and c3 != inf:  # for Negative Edge
                vertices[i][j] = c1 if c1 < c2+c3 else c2+c3

ans = []
for i, a in enumerate(vertices):
    if a[i] < 0:
        print("NEGATIVE CYCLE")
        break
    ans.append(" ".join([str(n) if n != inf else "INF" for n in a]))
else:
    print("\n".join(ans))