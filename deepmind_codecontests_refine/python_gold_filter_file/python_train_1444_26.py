
# -*- coding: utf-8 -*-
import bisect
import heapq
import math
import random
import sys
from pprint import pprint
from collections import Counter, defaultdict, deque
from decimal import ROUND_CEILING, ROUND_HALF_UP, Decimal
from functools import lru_cache, reduce
from itertools import combinations, combinations_with_replacement, product, permutations
from operator import add, mul, sub

sys.setrecursionlimit(10000)


def read_int():
    return int(input())


def read_int_n():
    return list(map(int, input().split()))


def read_float():
    return float(input())


def read_float_n():
    return list(map(float, input().split()))


def read_str():
    return input().strip()


def read_str_n():
    return list(map(str, input().split()))


def error_print(*args):
    print(*args, file=sys.stderr)


def mt(f):
    import time

    def wrap(*args, **kwargs):
        s = time.time()
        ret = f(*args, **kwargs)
        e = time.time()

        error_print(e - s, 'sec')
        return ret

    return wrap


@mt
def slv(N, S):
    if S == N:
        return N + 1

    def f(b, n):
        if n < b:
            return n
        return f(b, n//b) + n % b

    for b in range(2, int(math.sqrt(N)) + 1):
        s = f(b, N)
        if s == S:
            return b

    cnd = []
    for p in range(1, int(math.sqrt(N))+1):
        b = (N - S) // p + 1
        if b < 2:
            continue
        s = f(b, N)
        if s == S:
            cnd.append(b)

    if cnd:
        return min(cnd)

    return -1


def main():
    N = read_int()
    S = read_int()

    print(slv(N, S))


if __name__ == '__main__':
    main()
