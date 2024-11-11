"""
Codeforces Round #329 (Div. 2)

Problem 593 B. Anton and Lines

@author yamaton
@date 2015-11-04
"""

import itertools as it
import functools
import operator
import collections
import math
import sys


EPSILON = 0.0000001

def solve(x1, x2, kbs):
    at_x1 = [k*(x1 + EPSILON) + b for (k, b) in kbs]
    at_x2 = [k*(x2 - EPSILON) + b for (k, b) in kbs]
    order1 = [i for i, _ in sorted(enumerate(at_x1), key=operator.itemgetter(1))]
    print_stderr('at_x1:', at_x1)
    print_stderr('at_x2:', at_x2)
    return any(at_x2[i] > at_x2[j] for (i, j) in zip(order1, order1[1:]))


def print_stderr(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)


def tf_to_yn(tf):
    return 'YES' if tf else 'NO'


def main():
    n = int(input())
    [x1, x2] = [int(i) for i in input().strip().split()]
    kbs = [tuple(int(i) for i in input().strip().split()) for _ in range(n)]
    result = solve(x1, x2, kbs)
    print(tf_to_yn(result))


if __name__ == '__main__':
    main()
