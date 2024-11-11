from sys import stdin
import heapq

n = int(stdin.readline())

balls = [int(x) for x in stdin.readline().split()]

balls.sort()

counts = {}

for x in balls:
    if x in counts:
        counts[x] += 1
    else:
        counts[x] = 1

q = []

for x in counts:
    heapq.heappush(q, [-counts[x], x])

snowmen = []

while len(q) >= 3:
    a = heapq.heappop(q)
    b = heapq.heappop(q)
    c = heapq.heappop(q)

    a[0] += 1
    b[0] += 1
    c[0] += 1

    s = [str(x) for x in sorted([a[1], b[1], c[1]], reverse=True)]
    snowmen.append(s)

    if a[0] < 0:
        heapq.heappush(q, a)
    if b[0] < 0:
        heapq.heappush(q, b)
    if c[0] < 0:
        heapq.heappush(q, c)
print(len(snowmen))
for x in snowmen:
    print(' '.join(x))
