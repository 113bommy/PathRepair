#!/usr/bin/python

import sys
#use ./ex1.py < input_ex1.py
    
def solve(N, K):
    if N == 1:
        return K
    res = int((K-1)/N) + 1
    if N % K != 0:
        res = max(2, res)
    return res
    
    
def run():
    out = ""    
    T = int(input())
    for i in range(T):
        N, K = [int(x) for x in input().split()]
        print(solve(N, K))

run()

