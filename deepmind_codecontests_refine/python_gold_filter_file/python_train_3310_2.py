import heapq
n, m = map(int, input().split())

a = list(map(lambda x: -int(x), input().split()))
heapq.heapify(a)

for i in range(m):
    heapq.heappush(a, int(heapq.heappop(a)/2))

print(-sum(a))