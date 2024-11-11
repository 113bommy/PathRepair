#!/usr/bin/env python3
from heapq import *
from collections import defaultdict

n = int(input())
r = map(int, input().split())
H = defaultdict(int)
for t in r:
    H[t] += 1

D = [(-1 * v, k) for k, v in H.items()]
heapify(D)
ret = []
while len(D) > 2:
    a, b, c = heappop(D), heappop(D), heappop(D)

    ret.append(sorted([a[1], b[1], c[1]], reverse=True))

    for x, xi in ((i + 1, j) for i, j in (a, b, c)):
        if x:
            heappush(D, (x, xi))

print(len(ret))
for a, b, c in ret:
    print(a, b, c)
