#! /usr/bin/env python3
# -*- coding: utf-8 -*-
# vim:fenc=tf-8
#

"""
"""

from collections import defaultdict
from collections import Counter

import sys
input = sys.stdin.readline

def solve(n, x, a):
    s = sum(a)
    if s % x != 0:
        print(n)
        return 0
    b = list(map(lambda aa: aa % x,a))
    if len([i for i in b if i != 0]) == 0:
        print(-1)
        return 0
    i = 0
    while b[i] == 0:
        i += 1
    l1 = n - i - 1
    i = n-1
    while b[i] == 0:
        i -= 1
    l2 = i
    print(max(l1,l2))



def main():
    t = int(input())
    for i in range(t):
        n, x = map(int,input().split())
        a = list(map(int,input().split()))
        solve(n, x, a)


if __name__ == "__main__":
    main()