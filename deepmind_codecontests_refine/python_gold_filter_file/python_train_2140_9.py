import sys
import bisect
# import heapq
from math import ceil,floor


RI = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()
mod = 10**9+7
# for _ in range(int(ri())):

n,m = RI()
a = RI()
b = RI()
b.sort()
b = [-10**10] + b + [10**10]
# print(b)
r=  -1
for i in range(len(a)):

    l = bisect.bisect_left(b,a[i])
    if l != 0:
        dist = min(a[i]-b[l-1],b[l]-a[i])
    else :
        dist = b[l]-a[i]
    # print(b[l],b[l])
    r=  max(dist,r) 

print(r)
