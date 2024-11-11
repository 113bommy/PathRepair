import sys
import math
from math import gcd,floor,sqrt,log,ceil
from collections import defaultdict


sys.setrecursionlimit(100000000)
mod=1000000007
iin    =lambda: int(input())
sin  =lambda: input()
ilist   =lambda: list(map(int,input().split()))
slist   =lambda: list(map(str,input().split()))
imap    =lambda: map(int,input().split())


def count(s,x):
    ans = 0
    for i in s:
        if i == x:
            ans += 1
    return ans


def mid(n):
    return ceil(n/2)


def solve():
    k = iin()
    l = iin()
    m = iin()
    n = iin()
    d = iin()
    a = [0]*(d+1)
    for i in range(1,d+1):
        if i %k==0 or i%l==0 or i%m==0 or i%n==0:
            a[i] = 1
    print(a.count(1))





for _ in range(1):
    solve() 