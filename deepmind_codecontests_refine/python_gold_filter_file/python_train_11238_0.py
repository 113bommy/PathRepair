#!/usr/bin/env python
# -*- coding: utf-8 -*-

import math
import itertools

def sieve_of_erastosthenes(num):
    input_list = [False if i % 2 == 0 or i % 3 == 0 or i % 5 == 0 else True for i in range(num)]
    input_list[0] = input_list[1] = False
    input_list[2] = input_list[3] = input_list[5] = True
    sqrt = math.sqrt(num)

    for serial in range(3, num, 2):
        if serial >= sqrt:
            return input_list
        for s in range(serial ** 2, num, serial): 
            input_list[s] = False

primeTable = sieve_of_erastosthenes(10**6)

while True:
    N,P = map(int,input().split(" "))
    if N == -1 and P == -1:
        break
    start = N+1
    while primeTable[start] is False:
        start += 1
    prime_list = []
    count = 0
    i = 0
    while count != P:
        if primeTable[start + i]:
            prime_list.append(start+i)
            count += 1
        i += 1
    print(sorted([sum(t) for t in itertools.combinations_with_replacement(prime_list,2)])[P-1])