from functools import reduce
import os
import sys
from math import *
from collections import *
from fractions import *
from bisect import *
from heapq import *
from io import BytesIO, IOBase
input = lambda: sys.stdin.readline().rstrip("\r\n")
def value(): return tuple(map(int, input().split())) # multiple values
def arr(): return [int(i) for i in input().split()] # array input
def sarr(): return [int(i) for i in input()] #array from string
def starr(): return [str(x) for x in input().split()] #string array
def inn(): return int(input()) # integer input
def svalue(): return tuple(map(str, input().split())) #multiple string values
def parr(): return [(value()) for i in range(n)] # array of pairs
mo = 1000000007
# ----------------------------CODE------------------------------#
def factors(n):         #return list
    return list(set(reduce(list.__add__,
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))
def gcd(a, b):
    while b:
        a, b = b, a%b
    return a
n=inn()
a=factors(n)
ln=len(a)
x,y=100000000,10000000
mx=100000000000000
#print(a)
for i in range(ln):
    val=n//a[i]
    res=gcd(a[i],val)
    res=(val*a[i])//res
    if(res==n):
        if(max(val,a[i])<mx):
            mx=max(val,a[i])
            x,y=a[i],val
print(x,y)


