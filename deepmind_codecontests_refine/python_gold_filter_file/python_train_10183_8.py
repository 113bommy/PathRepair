import heapq

N, K = map(int, input().split())
sushi = []
for i in range(N):
    t, d = map(int, input().split())
    heapq.heappush(sushi, (-d, t))

total = 0
types = set()
remain = []
for i in range(K):
    d, t = heapq.heappop(sushi)
    total -= d
    if t not in types:
        types.add(t)
    else:
        # 余りの寿司はremainにappend
        heapq.heappush(remain, -d)

types_len = len(types)
ans = total + types_len ** 2

while sushi and remain:
    d, t = heapq.heappop(sushi)
    if t not in types:
        types.add(t)
        remain_d = heapq.heappop(remain)
        total = total - d - remain_d
        types_len += 1
        ans = max(ans, total + types_len ** 2)

print(ans)
