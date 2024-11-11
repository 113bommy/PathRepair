from collections import deque
def bfs(special):
    count = 0
    seen = {special:0}
    q = deque()
    q.appendleft(special)
    while q:
        curr = q.pop()
        for node in adj[curr]:
            if node not in seen:
                seen[node] = 0
                q.appendleft(node)
        count += 1
    return count

for i in range(int(input())):
    nodes, special = map(int, input().split())
    adj = [[] for i in range(nodes + 1)]
    for i in range(nodes - 1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)
    if len(adj[special]) <= 1:
        print('Ayush')
    else:
        count = bfs(special)
        if (count - 2)%2 == 0:
            print('Ayush')
        else:
            print('Ashish')