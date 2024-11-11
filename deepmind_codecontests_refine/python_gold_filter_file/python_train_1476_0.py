# -*- coding: utf-8 -*-
import sys
from operator import itemgetter
from fractions import gcd
from math import ceil, floor
from copy import deepcopy
from itertools import accumulate
from collections import Counter
import math
from functools import reduce
from bisect import bisect_right
sys.setrecursionlimit(200000)
input = sys.stdin.readline
def ii(): return int(input())
def mi(): return map(int, input().rstrip().split())
def lmi(): return list(map(int, input().rstrip().split()))
def li(): return list(input().rstrip())
def debug(x): print("debug: ", x, file=sys.stderr)
# template


def main():
    n = ii()
    a = [tuple(mi()) for i in range(4 * n + 1)]
    # print(a)
    for x in range(60):
        for y in range(60):
            for m in range(60):
                ans = []
                for i in range(4 * n + 1):
                    if ((x == a[i][0] or x + m == a[i][0]) and y <= a[i][1] <= y+m) or ((y == a[i][1] or y + m == a[i][1]) and x <= a[i][0] <= x+m):
                        continue
                    else:
                        ans.append(a[i])
                if len(ans) == 1:
                    # print(x, y, m)
                    print(ans[0][0], ans[0][1])
                    sys.exit()


if __name__ == '__main__':
    main()
