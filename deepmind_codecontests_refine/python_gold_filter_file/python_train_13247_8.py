# -*- coding:utf-8 -*-

"""

created by shuangquan.huang at 2020/6/30

"""

import collections
import time
import os
import sys
import bisect
import heapq
from typing import List


def get(A, x):
    curr, mx = 0, 0
    for v in A:
        curr += x * v
        mx = max(mx, curr)
        if curr < 0:
            curr = 0
    
    return mx

def solve(N, S, T):
    A = []
    for s, t in zip(S, T):
        if s != t:
            if s == 1:
                A.append(1)
            else:
                A.append(-1)
    
    if sum(A or [0]) != 0:
        return -1
    
    
    return max(get(A, 1), get(A, -1))


if __name__ == '__main__':
    N = int(input())
    S = [int(x) for x in list(input())]
    T = [int(x) for x in list(input())]
    print(solve(N, S, T))