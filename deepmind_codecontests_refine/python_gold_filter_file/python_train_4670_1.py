import sys
input = sys.stdin.readline

from collections import deque

# 伸ばせる限り伸ばせば答

N,M = map(int,input().split())
AB = [[int(x) for x in input().split()] for _ in range(M)]

graph = [[] for _ in range(N+1)]
for a,b in AB:
    graph[a].append(b)
    graph[b].append(a)

path = deque(AB[0])
visited = set(AB[0])

while True:
    x = path[0]
    update = False
    for y in graph[x]:
        if y not in visited:
            path.appendleft(y)
            visited.add(y)
            update = True
            break
    if not update:
        break
while True:
    x = path[-1]
    update = False
    for y in graph[x]:
        if y not in visited:
            path.append(y)
            visited.add(y)
            update = True
            break
    if not update:
        break

print(len(path))
print(*path)