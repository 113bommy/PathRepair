#                          JAI SHREE RAM

import math; from collections import *
import sys; from functools import reduce

# sys.setrecursionlimit(10**6)
def get_ints(): return map(int, input().strip().split())
def get_list(): return list(get_ints())
def get_string(): return list(input().strip().split())
def printxsp(*args): return print(*args, end="")
def printsp(*args): return print(*args, end=" ")

UGLYMOD = int(1e9)+7; SEXYMOD = 998244353; MAXN = int(1e5)

# sys.stdin=open("input.txt","r");sys.stdout=open("output.txt","w")

# for _testcases_ in range(int(input())):
a, b, c = get_ints()
print(min(a+b+c, a+a+b+b, a+c+c+a, b+c+c+b))

'''
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
THE LOGIC AND APPROACH IS MINE @luctivud ( UDIT GUPTA )
Link may be copy-pasted here if it's taken from other source.
DO NOT PLAGIARISE.
>>> COMMENT THE STDIN!! CHANGE ONLINE JUDGE !!
'''