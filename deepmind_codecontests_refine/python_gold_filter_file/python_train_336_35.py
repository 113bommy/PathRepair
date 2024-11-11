#This code is contributed by Siddharth
# import time
# import heapq
# import sys
import math
from collections import *
# from heapq import *
# import math
# import bisect
# from itertools import *
mod=10**9+7
# input=sys.stdin.readline

# def gcd(a, b):
#     if b == 0:
#         return a
#     else:
#         return gcd(b, a % b)
#
#
# def lcm(a, b):
#     return (a * b) // gcd(a, b)
#
#
# def ncr(n, r):
#     return math.factorial(n) // (math.factorial(n - r) * math.factorial(r))
#
#
# def npr(n, r):
#     return math.factorial(n) // math.factorial(n - r)
#
#
# def seive(n):
#     primes = [True] * (n + 1)
#     ans = []
#
#     for i in range(2, n):
#         if not primes[i]:
#             continue
#
#         j = 2 * i
#         while j <= n:
#             primes[j] = False
#             j += i
#
#     for p in range(2, n + 1):
#         if primes[p]:
#             ans += [p]
#
#     return ans
#

fact=1
n=int(input())
a=n
while a>0:
    fact=(fact*a)%mod
    a-=1
print((fact-pow(2,n-1,mod))%mod)