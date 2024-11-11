import heapq
N, M = map(int, input().split())

a = list(map(lambda x: -int(x), input().split()))
heapq.heapify(a)

for i in range(M):
    heapq.heappush(a, int(heapq.heappop(a)/2))

print(-sum(a))