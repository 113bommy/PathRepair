# -*- coding: utf-8 -*-
import sys
from collections import deque, defaultdict
from math import sqrt, factorial
def input(): return sys.stdin.readline()[:-1] # warning not \n
# def input(): return sys.stdin.buffer.readline()[:-1] # warning bytes
# def input(): return sys.stdin.buffer.readline()[:-1].decode('utf-8')


def solve():
    a, b, x, y = [int(x) for x in input().split()]
    a = x - a
    b = y - b
    if a == 0 or b == 0:
        print(1)
    else:
        print(a * b + 1)

t = 1
t = int(input())
for case in range(1,t+1):
    ans = solve()




"""

1 2 3 .. d1 1 2 3 4 5 .. d2


"""

