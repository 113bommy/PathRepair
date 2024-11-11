#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8
#

"""
AGC023 B
"""

from itertools import product

n = int(input())
sli = [input() for i in range(n)]

ans = 0
for k in range(n):
    if all((sli[i][j] == sli[(j+k) % n][(i-k) % n] for i, j in product(range(n), repeat=2))):
        ans += n

print(ans)

