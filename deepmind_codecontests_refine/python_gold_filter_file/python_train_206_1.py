n = int(input())
points = [complex(*map(int, input().split())) for _ in range(n)]
edges = [p1 - p0 for p0, p1 in zip(points, points[1:] + [points[0]])]
prev = edges[0]
while edges:
    edge = edges.pop()
    if edge.real * prev.imag - prev.real * edge.imag < -1e-6:
        print(0)
        break
    prev = edge
else:
    print(1)