# -*- coding: utf-8 -*-
import sys
import math
import os
import itertools
import string
import heapq
from _collections import defaultdict
from functools import lru_cache

class Scanner():
    def int():
        return int(sys.stdin.readline().rstrip())
    def string():
        return sys.stdin.readline().rstrip()
    def map_int():
        return [int(x) for x in Scanner.string().split()]
    def string_list(n):
        return [input() for i in range(n)]
    def int_list_list(n):
        return [Scanner.mapInt() for i in range(n)]
    def int_cols_list(n):
        return [int(input()) for i in range(n)]
        
class Math():
    def gcd(a,b):
        if b == 0:
            return a
        return Math.gcd(b,a % b)
    def lcm(a,b):
        return (a * b) // Math.gcd(a,b)
    def roundUp(a,b):
        return -(-a // b)
    def toUpperMultiple(a,x):
        return Math.roundUp(a,x) * x
    def toLowerMultiple(a,x):
        return (a // x) * x
    def nearPow2(n):
        if n <= 0:
            return 0
        if n & (n - 1) == 0:
            return n
        ret = 1
        while(n > 0):
            ret <<= 1
            n >>= 1
        return ret
    def isPrime(n):
        if n < 2:
            return False
        if n == 2:
            return True
        if n % 2 == 0:
            return False
        d = int(n ** 0.5) + 1
        for i in range(3,d + 1,2):
            if n % i == 0:
                return False
        return True

MOD = int(1e09) + 7

def main():
    N = Scanner.int()
    A = Scanner.map_int()
    if N == 1:
        print(A[0])
        return
    B = [0] * N
    i = 0
    j = N - 1 - N % 2
    for i in range(N // 2):
        B[i] = A[j]
        j -= 2
    i += 1
    B[i] = A[0]
    j = 2
    for i in range(i + 1,N):
        B[i] = A[j]
        j += 2
    if N % 2 == 1:
        B.reverse()
    print(*B)
    return

if __name__ == "__main__":
    main()
