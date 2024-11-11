import io, os
import sys 
from sys import stdin

from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, namedtuple
from heapq import heappush, heappop
from math import gcd, ceil, floor, factorial, sqrt
from itertools import combinations, permutations

# input = sys.stdin.buffer.readline
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def work_1(n, a, b):
    if a == b:
        return 0 
    if a.count('1') == 0:
        return -1 
    
    cnt = 0 
    zero = one = 0
    t1 = t2 = 0 
    for i in range(n):
        if a[i] != b[i]:
            cnt += 1 
            if a[i] == '0':
                t1 += 1 
            else:
                t2 += 1 
        else:
            if a[i] == '0':
                zero += 1 
            else:
                one += 1 
    INF = float('inf')
    ans = INF 
    if cnt % 2 == 0 and t1 == t2 and t1 > 0:
        ans = min(ans, cnt)
    # if zero > 0 and one > 0 and (one + zero) % 2 == 1:
    if zero >= 0 and one > 0 and (one + zero) % 2 == 1 and zero + 1 == one:
        ans = min(ans, one + zero)

    if cnt % 2 == 1:
        if one == 1 and zero == 0:
            ans = min(ans, 1)
    # if one >= 1 and zero >= 1 and t2 == 1:
    #     ans = min(ans, 2)

    if ans == INF:
        ans = -1 
    return ans 

def work(n, a, b):
    if a == b:
        return 0 
    
    t01 = t10 = 0 
    t0 = t1 = 0 
    for i in range(n):
        if a[i] == b[i]:
            if a[i] == '0':
                t0 += 1 
            else:
                t1 += 1 
        else:
            if a[i] == '0':
                t01 += 1 
            else:
                t10 += 1 
    INF = float('inf')
    ans = INF 
    if (t01 + t10) % 2 == 0 and t01 == t10 and t01 > 0:
        ans = min(ans, t01 + t10)
    if (t0 + t1) % 2 == 1 and t0 + 1 == t1:
        ans = min(ans, t0 + t1)
    if ans == INF:
        ans = -1 
    return ans 


# sys.setrecursionlimit(200010)
def main():
    test = int(input())

    for idt in range(test):
        n = int(input())
        # n, m = map(int, input().split())
        # a = list(map(int, input().split()))
        a = input().strip("\r\n")
        b = input().strip("\r\n")
        # print("info", idt, a, b)
        # res = work(n, a, b)
        res = work_1(n, a, b)
        print(res)
    
    return 


if __name__ == '__main__':
    main()