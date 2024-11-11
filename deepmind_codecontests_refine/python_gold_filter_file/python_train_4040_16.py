import heapq
N, M = map(int, input().split())
W = [tuple(map(int, input().split())) for i in range(N)]
W.sort()
h = []

j = 0
ans = 0
for i in range(M+1):
    while j < N and W[j][0] < i+1:
        heapq.heappush(h, (-W[j][1], W[j][1]))
        j += 1
    if h:
        p = heapq.heappop(h)
        ans += p[1]

print(ans)