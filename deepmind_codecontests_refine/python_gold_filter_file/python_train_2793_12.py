# -*- coding: utf-8 -*-
from bisect import bisect, bisect_left, insort
from itertools import accumulate
def inpl(): return tuple(map(int, input().split()))

K = int(input())
A = inpl()
if A[-1] != 2:
    print(-1)
    exit()

l, r = 2, 3
for a in A[:-1][::-1]:
    l = (l//a)*a + int(l%a!=0)*a
    r = (r//a)*a + (a-1)
    if r < l:
        print(-1)
        break
else:
    print(l, r)
