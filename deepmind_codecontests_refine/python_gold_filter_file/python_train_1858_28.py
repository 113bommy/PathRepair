#!/usr/bin/env python3
from collections import Counter

def check():
    h, w = map(int, input().split()) 
    c = Counter()
    for i in range(h):
        c.update(input())
    cc = {}
    cc[4] = (h >> 1) * (w >> 1)
    cc[2] = (h & 1) * (w >> 1) + (w & 1) * (h >> 1)
    cc[1] = (h & 1) * (w & 1)
    tt = list(c.values())
    for v in [4, 2, 1]:
        for i in range(len(tt)):
            k = min(cc[v], tt[i] // v)
            tt[i] -= k * v
            cc[v] -= k
    return sum(tt) == 0


print(["No", "Yes"][check()])
