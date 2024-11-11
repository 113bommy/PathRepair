from heapq import heappop, heappush

N, M, S, T = map(int, input().split())

GA = [[] for _ in range(N+1)]
GB = [[] for _ in range(N+1)]

for _ in range(M):
    u, v, a, b = map(int, input().split())
    GA[u].append([v, a])
    GA[v].append([u, a])
    GB[v].append([u, b])
    GB[u].append([v, b])

costa = [10**16]*(N+1)
costb = [10**16]*(N+1)

costa[S] = 0
costb[T] = 0
Q = [[0, S]]


while Q:
    c, p = heappop(Q)
    if costa[p] < c:
        continue

    for q, a in GA[p]:
        if costa[q] > c+a:
            costa[q] = c+a
            heappush(Q, [c+a, q])

Q = [[0, T]]

while Q:
    c, p = heappop(Q)
    if costb[p] < c:
        continue

    for q, b in GB[p]:
        if costb[q] > c+b:
            costb[q] = c+b
            heappush(Q, [c+b, q])

ans = []
tmp = 10**16

for i in range(N, -1, -1):
    
    tmp = min(tmp, costa[i] + costb[i])
    ans.append(10**15 - tmp)

print(*ans[::-1][1:], sep="\n")