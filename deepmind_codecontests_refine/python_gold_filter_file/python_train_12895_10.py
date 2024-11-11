# -*- coding: utf-8 -*-

import sys
import os
import math
import itertools


def is_prime(q):
    q = abs(q)
    if q == 2: return True
    if q < 2 or q&1 == 0: return False
    return pow(2, q-1, q) == 1

for s in sys.stdin:
    n = int(s)

    for i in range(n-1, 0, -1):
        if is_prime(i):
            answer0 = i
            break

    for i in range(n+1, 100000, 1):
        if is_prime(i):
            answer1 = i
            break

    print(answer0, answer1)