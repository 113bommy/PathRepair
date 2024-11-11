import heapq

N, K = list(map(int, input().split()))
td = []
td_ = []
group = set()
total = 0

for i in range(N):
    t, d = list(map(int, input().split()))
    heapq.heappush(td, (-d, t))

for i in range(K):
    d, t = heapq.heappop(td)
    total -= d
    if t not in group:
        group.add(t)
    else:
        heapq.heappush(td_, -d)

ans = len(group)**2 + total

while td and td_:
    d, t = heapq.heappop(td)

    if t not in group:
        group.add(t)
        d_ = heapq.heappop(td_)
        total = total - d_ - d
        ans = max(ans, len(group)**2 + total)
print(ans)