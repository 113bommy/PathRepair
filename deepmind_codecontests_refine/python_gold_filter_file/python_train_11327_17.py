from heapq import heappop, heappush

n, m = map(int, input().split())
a = list(map(int, input().split()))
q = []
for x in a:
  heappush(q, [-x, 1])
for i in range(m):
  b, c = map(int, input().split())
  heappush(q, [-c, b])
r = []
k = 0
while k < n:
  c, b = heappop(q)
  c = -c
  r += [c] * b
  k += b
print(sum(r[:n]))
