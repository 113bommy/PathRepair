import math
from collections import deque, defaultdict
from sys import stdin, stdout
input = stdin.readline
# print = stdout.write
listin = lambda : list(map(int, input().split()))
mapin = lambda : map(int, input().split())
n = int(input())
a = list(map(int, input().split()))
ma = 0
mi = 3*10**5
if a[0]!=a[-1]:
    print(n-1)
else:
    for i in range(n):
        if a[i]!=a[0]:
            mi = min(mi, i)
            ma = max(i, ma)
    print(max(ma, mi, n-1-mi, n-1-ma))