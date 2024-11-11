#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
input:
5 8

output:
390625
"""

import sys


def mod_pow(x, n, _mod):
    res = 1
    while n > 0:
        # check n is odd number
        if n % 2:
            res = res * x % _mod
        x = pow(x, 2) % _mod
        n //= 2
    return res


if __name__ == '__main__':
    _input = sys.stdin.readlines()
    n1, n2 = map(int, _input[0].split())
    M = 1000000007
    # print(pow(n1, n2, M))
    print(mod_pow(n1, n2, M))