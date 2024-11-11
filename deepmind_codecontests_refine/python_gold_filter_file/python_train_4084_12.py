# python3

#===============================================================================
from collections import defaultdict, Counter
from functools import lru_cache
from heapq import heappush, heappop
from math import gcd, floor, ceil
from sys import stdin, stdout

def ilist():
    return [int(x) for x in stdin.readline().strip().split(" ")]
def iint():
    return int(stdin.readline().strip())
def istr():
    return stdin.readline().strip()
#===============================================================================


def solve(a):
    n = len(a)
    count = [0] * 32
    for i in range(n):
        for j in range(32):
            count[j] += (a[i] >> j) & 1
    maxi = [0, 0]
    for i in range(n):
        num = 0
        for j in range(32):
            b = (a[i] >> j) & 1
            if b == 1 and count[j] == 1:
                num += (1 << j)
        if num > maxi[0]:
            maxi = [num, i]
    res = [a[maxi[1]]]
    for i in range(n):
        if i != maxi[1]:
            res.append(a[i])
    return " ".join([str(e) for e in res])


if __name__ == '__main__':
    n = iint()
    a = ilist()
    print(solve(a))
