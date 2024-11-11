import time
from queue import Queue
from itertools import accumulate
from io import BytesIO, IOBase
from itertools import combinations
import threading
from collections import deque
from functools import reduce, cmp_to_key
import sys
from math import sqrt
import heapq
import random
import math
from collections import defaultdict
from collections import Counter
import io
import os
import bisect
from fractions import Fraction


# sys.setrecursionlimit(200000)
# input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


def input():
    return sys.stdin.readline().strip()


def iinput():
    return int(input())


def tinput():
    return input().split()


def rinput():
    return map(int, tinput())


def rlinput():
    return list(rinput())


mod = int(1e9)+7


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))


def swap(arr, a, b):
    arr[a], arr[b] = arr[b], arr[a]
# ----------------------------------------------------
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')


# ----------------------------------------------------------------
n = iinput()
for _ in range(n):
    v = iinput()
    ans = []
    for i in range(1,(v//2)*2+1,2):
        ans.append(i+1)
        ans.append(i)
    if v%2:
        ans.append(v)
    if v >=3 and v%2:
        ans[-1],ans[-3] = ans[-3],ans[-1]
    print(*ans)