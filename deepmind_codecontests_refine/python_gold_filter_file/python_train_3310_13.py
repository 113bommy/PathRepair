#!/usr/bin/env python3

from bisect import insort_right

n, m, *a = map(int, open(0).read().split())
a.sort()
for _ in range(m):
    insort_right(a, a.pop() >> 1)
print(sum(a))
