import re
import sys
from bisect import bisect, bisect_left, insort, insort_left
from collections import Counter, defaultdict, deque
from copy import deepcopy
from decimal import Decimal
from fractions import gcd
from itertools import (
    accumulate, combinations, combinations_with_replacement, groupby,
    permutations, product)
from math import (
    acos, asin, atan, ceil, cos, degrees, factorial, hypot, log2, pi, radians,
    sin, sqrt, tan)
from operator import itemgetter, mul
from string import ascii_lowercase, ascii_uppercase, digits


def inp():
    return(int(input()))


def inlist():
    return(list(map(int, input().split())))


def instr():
    s = input()
    return(list(s[:len(s)]))


def invr():
    return(map(int, input().split()))


def gcd_custom(a, b):
    if a == 0 or b == 0:
        return a, b
    if a >= 2*b:
        return gcd_custom(a % (2*b), b)
    elif b >= 2*a:
        return gcd_custom(a, b % (2*a))
    else:
        return a, b


a, b = invr()

c, d = gcd_custom(a, b)
print(c, d)
