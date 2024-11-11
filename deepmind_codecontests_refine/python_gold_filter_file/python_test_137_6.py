import io, os
import sys 
from sys import stdin

from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, namedtuple
from heapq import heappush, heappop
from math import gcd, ceil, floor, factorial, sqrt
from itertools import combinations, permutations

input = sys.stdin.buffer.readline
# input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
# input = sys.stdin.readline

def get(p):
    n = len(p)
    i = 0 
    while i < n and p[i] == "0":
        i += 1 
    return p[i:]
def work(stt, end):
    n, m = len(stt), len(end)
    # if n > m:
    #     return False 
    if stt == end:
        return True 
    
    q = deque()
    q.append(stt)
    seen = set()

    while q:
        t = q.popleft()
        if t not in seen:
            seen.add(t)

            p = t[::-1]
            p = get(p)
            if p == end:
                return True 
            if len(p) <= m:
                q.append(p)
            p = t + "1"
            p = p[::-1]
            p = get(p)
            if len(p) <= m:
                q.append(p)
            if p == end:
                return True 
    return False 

# sys.setrecursionlimit(200010)
# https://codeforces.com/contest/1618/problem/F
def main():
    test = 1

    for idt in range(test):
        # n = int(input())
        a, b = map(int, input().split())
        # a = list(map(int, input().split()))
        stt = bin(a)[2:]
        end = bin(b)[2:]
        # print(stt)
        # print(end)
        if work(stt, end):
            print("YES")
        else:
            print("NO")
    return 


if __name__ == '__main__':
    main()