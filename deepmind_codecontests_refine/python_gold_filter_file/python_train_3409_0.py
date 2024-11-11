# aadiupadhyay
from ntpath import realpath
import os.path
from math import gcd, floor, ceil
from collections import *
import sys
mod = 1000000007
INF = float('inf')
def st(): return list(sys.stdin.readline().strip())
def li(): return list(map(int, sys.stdin.readline().split()))
def mp(): return map(int, sys.stdin.readline().split())
def inp(): return int(sys.stdin.readline())
def pr(n): return sys.stdout.write(str(n)+"\n")
def prl(n): return sys.stdout.write(str(n)+" ")


if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')


n = inp()
l = sorted(li())
ans = 1
val = [l[0]]
s = set(l)
for i in range(n):
    for j in range(33):
        a, b = l[i] - (1 << j), l[i]+(1 << j)
        if a in s and b in s:
            print(3)
            print(a, l[i], b)
            exit()
        if (a in s) and (b not in s):
            ans = 2
            val = [a, l[i]]
        if (a not in s) and (b in s):
            ans = 2
            val = [l[i], b]
pr(ans)
print(*val)
