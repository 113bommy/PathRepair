import math
from collections import deque, defaultdict
from sys import stdin, stdout
import bisect
input = stdin.readline
# print = stdout.write
listin = lambda : list(map(int, input().split()))
mapin = lambda : map(int, input().split())
n, m, ta, tb, k = mapin()
a = listin()
b = listin()
ans = 0
try:
    for i in range(k+1):
        x = bisect.bisect_left(b, a[i]+ta)
        ans = max(ans, b[x+k-i]+tb)
    print(ans)
except:
    print(-1)