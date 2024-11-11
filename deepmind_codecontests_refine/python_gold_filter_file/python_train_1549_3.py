from collections import deque

N, K = map(int, input().split())
T = [[] for i in range(N)]
E = []
for i in range(N-1):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    T[a].append(b)
    T[b].append(a)
    E.append((a, b))


def bfs(n):
    visited = [False] * N
    dist = [0] * N
    queue = deque([n])
    while queue:
        node = queue.pop()
        if visited[node]:
            continue
        visited[node] = True
        for n in T[node]:
            if not visited[n]:
                dist[n] = dist[node] + 1
                queue.appendleft(n)
    return dist


dist = []
for i in range(N):
    dist.append(bfs(i))

ans = float('inf')
if K % 2 == 0:
    # 全ての頂点について全探索
    for i in range(N):
        ans = min(ans, len([d for d in dist[i] if d > K / 2]))
else:
    # 全ての辺について全探索
    for a, b in E:
        adist = [(1 if min(d1, d2) > (K-1) / 2 else 0) for d1, d2 in zip(dist[a], dist[b])]
        ans = min(ans, sum(adist))

print(ans)
