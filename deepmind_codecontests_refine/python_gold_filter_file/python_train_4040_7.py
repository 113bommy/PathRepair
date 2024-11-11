import heapq

n,m = map(int,input().split())
lb = [[] for _ in range(10**5+5)]
for _ in range(n):
    a,b = map(int,input().split())
    lb[a].append(b)
res = 0
q = []
heapq.heapify(q)
for i in range(1,m+1):
    for b in lb[i]:
        heapq.heappush(q,b * (-1))
    if q:
        res += heapq.heappop(q) * (-1)

print(res)