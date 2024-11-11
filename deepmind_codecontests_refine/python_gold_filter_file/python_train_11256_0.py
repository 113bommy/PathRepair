a, s = list(map(int, input().split()))
graph = [[] for _ in range(a)]
for _ in range(a - 1):
    x, y = list(map(int, input().split()))
    graph[x-1].append(y-1)
    graph[y-1].append(x-1)
k = 0
for i in graph:
    if len(i) == 1:
        k += 1
print((s*2) / k)
