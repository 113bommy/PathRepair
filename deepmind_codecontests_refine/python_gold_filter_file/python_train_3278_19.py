from sys import stdin
from collections import deque
mod = 10**9 + 7
import sys
# sys.setrecursionlimit(10**6)
from queue import PriorityQueue
# def rl():
#     return [int(w) for w in stdin.readline().split()]
from bisect import bisect_right
from bisect import bisect_left
from collections import defaultdict
from math import sqrt,factorial,gcd,log2,inf,ceil
# map(int,input().split())
# # l = list(map(int,input().split()))
# from itertools import permutations
import heapq
# input = lambda: sys.stdin.readline().rstrip()
input = lambda : sys.stdin.readline().rstrip()
from sys import stdin, stdout
from heapq import heapify, heappush, heappop
from itertools import permutations

n = list(input())
if int(''.join(n))%8 == 0:
    print('YES')
    print(''.join(n))
    exit()

for i in range(len(n)):
    a = n[i]
    if int(a)%8 == 0:
        print('YES')
        print(a)
        exit()
    for j in range(i+1,len(n)):
        b = n[j]
        if int(a+b)%8 == 0:

            if a!='0':
              print('YES')
              print(a+b)
              exit()
        for k in range(j+1,len(n)):
            c = n[k]
            if int(a + b + c)%8 == 0:

                if a!='0':

                   print('YES')
                   print(a+b+c)
                   exit()

print('NO')






