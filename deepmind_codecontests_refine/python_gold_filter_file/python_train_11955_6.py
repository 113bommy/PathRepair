import collections, heapq
N, M = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]
XY = [[int(_) for _ in input().split()] for _ in range(M)]
G = collections.defaultdict(list)
for x, y in XY:
    G[x] += [y]
    G[y] += [x]
B = sorted([v, i] for i, v in enumerate(A))
visited = [0] * N
ans = 0
H = []
t = 0
for b in B:
    v, i = b
    if not visited[i]:
        visited[i] = 1
        ans += v
        q = G[i]
        t += 1
        while q:
            i = q.pop()
            if not visited[i]:
                visited[i] = 1
                heapq.heappush(H, [A[i], i])
                q += G[i]
if len(H) < t - 2:
    print('Impossible')
    exit()
elif t == 1:
    print(0)
    exit()
for _ in range(t - 2):
    v, i = heapq.heappop(H)
    ans += v
print(ans)
