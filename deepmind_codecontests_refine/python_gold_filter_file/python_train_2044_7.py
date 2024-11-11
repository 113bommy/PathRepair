from fractions import gcd
from datetime import date, timedelta
from heapq import*
import math
from collections import defaultdict, Counter, deque
import sys
from bisect import *
import itertools
import copy
sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7


def main():
    n = int(input())
    a = n * (n + 1) // 2
    print(a%2)
    a //=2
    ansl = []
    for i in range(n, 0, -1):
        if a > i:
            ansl.append(i)
            a-= i
        else:
            break
    if a > 0:
        ansl.append(a)
    ansl.sort()
    print(len(ansl),*ansl)



if __name__ == '__main__':
    main()
