from heapq import*
(N, M), *t = [map(int, s.split()) for s in open(0)]
q, z = [], 0
v = [[] for _ in [None] * 10**5]
for a, b in t:
    v[a - 1] += b,
for i in v[:M]:
    for j in i:
        heappush(q, -j)
    if q:
        z += -heappop(q)
print(z)