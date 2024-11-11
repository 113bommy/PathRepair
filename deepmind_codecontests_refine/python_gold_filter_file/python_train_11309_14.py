import re
import sys
from bisect import bisect, bisect_left, insort, insort_left
from collections import Counter, defaultdict, deque
from copy import deepcopy
from decimal import Decimal
from itertools import (
    accumulate, combinations, combinations_with_replacement, groupby,
    permutations, product)
from math import (acos, asin, atan, ceil, cos, degrees, factorial, gcd, hypot,
                  log2, pi, radians, sin, sqrt, tan)
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


n = inp()
a = inp()
b = inp()
if n % gcd(a, b) == 0:

    y = 0
    x = 0
    while y * b <= n:
        if (n - b*y) % a == 0:
            if (n-b*y) >= 0:
                x = (n - (b*y)) // a
                print("YES")
                print(x, y)
                break
        y += 1
    else:
        print("NO")


else:
    print("NO")
