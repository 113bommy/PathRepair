from collections import deque

def bfs(start):
    queue = deque([start])
    visited = []

    while queue:
        label = queue.pop()

        visited.append(label)

        for v in d[label]:
            if tekazu[v] == float("inf"):
                tekazu[v] = tekazu[label] + 1
                queue.appendleft(v)

    return

n = int(input())
d = [[] for _ in range(n)]

for _ in range(n - 1):
    a, b = map(int, input().split())
    d[a - 1].append(b - 1)
    d[b - 1].append(a - 1)

tekazu = [float("inf") for _ in range(n)]
tekazu[0] = 0
bfs(0)
tekazu_Fennec = tekazu

tekazu = [float("inf") for _ in range(n)]
tekazu[-1] = 0
bfs(n - 1)
tekazu_Snuke = tekazu

Fennec = 0
Snuke = 0

for i in range(n):
    if tekazu_Fennec[i] <= tekazu_Snuke[i]:
        Fennec += 1
    else:
        Snuke += 1

if Fennec > Snuke:
    print("Fennec")
else:
    print("Snuke")