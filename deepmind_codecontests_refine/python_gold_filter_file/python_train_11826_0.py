import sys
input=sys.stdin.readline
from collections import defaultdict as dc
from collections import Counter
from bisect import bisect_right, bisect_left
import math
from operator import itemgetter
from heapq import heapify, heappop, heappush
from queue import PriorityQueue as pq
n=int(input())
l=list(map(int,input().split()))
l.sort()
x=dc(int)
m=sys.maxsize
for i in range(n-1):
    p=abs(l[i]-l[i+1])
    x[p]+=1
    m=min(m,p)
print(m,x[m])