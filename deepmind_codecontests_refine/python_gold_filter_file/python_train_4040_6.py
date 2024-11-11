import heapq

N, M = map(int, input().split())
AB = [[] for i in range(10**5+1)]

for i in range(N):
    A, B = map(int, input().split())
    AB[A].append(-B)

hq = []
heapq.heapify(hq)

ans = 0
for i in range(1, M+1):
    for b in AB[i]:
        heapq.heappush(hq, b)

    if len(hq) > 0:
        ans += -heapq.heappop(hq)

print(ans)
