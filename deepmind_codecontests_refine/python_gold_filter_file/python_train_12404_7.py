import math
import heapq

n, m, r= map(int, input().split())
a = sorted(list(map(int, input().split())))
b = sorted(list(map(int, input().split())))

if a[0]<b[-1]:
    s = r//a[0]
    r-=s*a[0]
    print(r+s*b[-1])
else:
    print(r)