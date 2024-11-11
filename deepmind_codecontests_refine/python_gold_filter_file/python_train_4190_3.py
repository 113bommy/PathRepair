import sys
input = sys.stdin.readline

n, m = [int(i) for i in input().split()]
graph = [[] for i in range(n)]
for j in range(n - 1):
    v, u = [int(i) - 1 for i in input().split()]
    graph[v].append(u)
    graph[u].append(v)
parent = [0]*n
tin = [0]*n
tout = [0]*n
time = 0
queue = [(0, 0)]

while queue:
    current, visit = queue.pop()
    if visit == 0:
        queue.append((current, 1))
        time += 1
        tin[current] = time
        for child in graph[current]:
            if child != parent[current]:
                parent[child] = current
                queue.append((child, 0))
    else:
        tout[current] = time

for j in range(m):
    q = [int(i) - 1 for i in input().split()]
    q = q[1:]
    cin = 1
    cout = n
    for i in range(len(q)):
        q[i] = parent[q[i]]
        cin = max(cin, tin[q[i]])
        cout = min(cout, tout[q[i]])
    if cin > cout:
        print("NO")
    else:
        print("YES")