# -*- coding: utf-8 -*-

import sys
import os

A = [0, 0]
B = [0, 0]
C = [0, 0]
D = [0, 0]

for s in sys.stdin:
    l, r = map(float, s.split())

    if l >= 1.1:
        A[0] += 1
    elif l >= 0.6:
        B[0] += 1
    elif l >= 0.2:
        C[0] += 1
    else:
        D[0] += 1

    if r >= 1.1:
        A[1] += 1
    elif r >= 0.6:
        B[1] += 1
    elif r >= 0.2:
        C[1] += 1
    else:
        D[1] += 1

print(*A)
print(*B)
print(*C)
print(*D)