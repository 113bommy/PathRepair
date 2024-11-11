#!/usr/bin/python3
# -*- coding: <utf-8> -*-

import itertools as ittls
from collections import Counter

import string


def sqr(x):
    return x*x

def inputarray(func = int):
    return map(func, input().split())

# -------------------------------
# -------------------------------

N = int(input())

digit = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
teens = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

if N <= 9:
    print(digit[N])
elif N <= 20:
    secondteen = ["ten", "eleven", "twelve",
                  "thirteen", "fourteen", "fifteen",
                  "sixteen", "seventeen", "eighteen",
                  "nineteen", "twenty"]
    print(secondteen[N - 10])
else:
    x, y = divmod(N, 10)
    if y != 0:
        print(teens[x - 2] + '-' + digit[y])
    else:
        print(teens[x - 2])
