from fractions import gcd
# from datetime import date, timedelta
from heapq import*
import math
from collections import defaultdict, Counter, deque
from bisect import *
import itertools
import fractions
# import sys
# sys.setrecursionlimit(10 ** 7)
MOD = 10 ** 9 + 7
# input = sys.stdin.readline


def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    if n == 1:
        print(a[0])
        exit()
    elif n == k:
        print(sum(a))
        exit()
    
    ans = 0
    su = 0
    for i in range(k - 1):
        su+=a[i]
    for i in range(k-1,n):
        su += a[i]
        ans += su
        su-=a[i - k + 1]
    print(ans/(n - k + 1))

    

    



if __name__ == '__main__':
    main()
