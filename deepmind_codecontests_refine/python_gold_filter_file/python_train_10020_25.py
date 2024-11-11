#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=tf-8
#

"""
"""

from collections import defaultdict
from collections import Counter
import bisect

import sys
input = sys.stdin.readline


def solve():
    n, x = map(int,input().split())
    degx = 0
    for i in range(n-1):
        e = map(int,input().split())
        if x in e:
            degx += 1
    if degx <= 1:
        print("Ayush")
    elif n%2 == 0:
        print("Ayush")
    else:
        print("Ashish")

            

def main():
    t = int(input())
    for i in range(t):
        solve()


if __name__ == "__main__":
    main()