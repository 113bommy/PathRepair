# -*- coding: utf-8 -*-

import sys
import os
import math

for s in sys.stdin:

    n = int(s)
    if n == 0:
        break
    P = []

    for i in range(n):
        x, y = map(float, input().split(','))
        P.append(complex(x, y))

    def get_intersections(p0, p1):
        """
        :type p0: complex
        :type p1: complex
        :return:
        """
        dist = abs(p0 - p1)

        if dist > 2:
            return []
        elif dist == 2:
            return [(p0 + p1) / 2]
        else:
            m = (p0 + p1) / 2
            v = m - p0
            w = complex(v.imag, -v.real)
            n = w / abs(w)
            d = abs(v)
            l = math.sqrt(1 - d ** 2)

            inter0 = m + l * n
            inter1 = m - l * n
            return [inter0, inter1]


    intersections = []
    for i in range(n):
        for j in range(i+1, n):
            intersections += get_intersections(P[i], P[j])

    counts = []

    # each intersection, it is in how many circles?
    for intersection in intersections:
        cnt = 0
        for p in P:
            if abs(intersection - p) <= 1.01:
                cnt += 1
        counts.append(cnt)

    if counts:
        print(max(counts))
    else:
        print(1)