#!/usr/bin/env python
# -*- coding: utf-8 -*-


"""
input:
3 8

output:
3 -1
"""

import sys


def ext_euclid(a, b):
    if b == 0:
        return 1, 0
    else:
        x, y = ext_euclid(b, a % b)
        x, y = y, (x - (a // b) * y)
        return x, y


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    n1, n2 = map(int, _input[0].split())
    print(*ext_euclid(n1, n2))