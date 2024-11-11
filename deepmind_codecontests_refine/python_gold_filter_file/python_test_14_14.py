import sys
import math
from math import factorial, inf, gcd, sqrt
from heapq import *
from functools import *
from itertools import *
from collections import *
from typing import *
from bisect import *
import random
from sys import stdin, stdout
sys.setrecursionlimit(10**5)


def inp():
    return stdin.readline().strip()


def iinp():
    return int(inp())


def mp():
    return map(int, inp().split())


def lmp():
    return list(mp())


t = iinp()
for i in range(t):
    n = iinp()
    a = lmp()
    b = sorted(a)
    ans = []
    for i in range(n):
        if a[0] != b[i]:
            j = a.index(b[i])
            ans.append([i + 1, j + i + 1, j])
            a.pop(j)
        else:
            a.pop(0)
    print(len(ans))
    for i, j, k in ans:
        print(i, j, k)
