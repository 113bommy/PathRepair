import sys
import math
import re
import string
def swap(a,l,r):
    temp=a[l]
    a[l]=a[r]
    a[r]=temp
def f():
    n,s=[int(x) for x in input().split(' ')]
    res = s//n if s%n==0 else s//n+1
    return (res)


def main():
    t = 1
    for i in range(t):
        print(f())

main()
