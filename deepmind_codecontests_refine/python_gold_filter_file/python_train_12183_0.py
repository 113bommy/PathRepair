V,E,r = map(int, input().split())
edges = []
for _ in range(E):
    tmp = [int(x) for x in input().split()]
    edges.append(tmp)
 
d = [float('inf') for _ in range(V)]
d[r] = 0
 
for _ in range(V-1):
    count = 0
    for x in edges:
        s,t,w = x
        if d[t] > d[s] + w:
            count += 1
            d[t] = d[s] + w
    if count == 0:
        break
 
for x in d:
    if x == float('inf'):
        print('INF')
    else:
        print(x)
