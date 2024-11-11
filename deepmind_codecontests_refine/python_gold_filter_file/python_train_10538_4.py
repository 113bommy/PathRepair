from bisect import bisect_left, bisect_right, insort
import sys
import heapq
from math import *
from collections import defaultdict as dd
from collections import deque
def data(): return sys.stdin.readline().strip()
def mdata(): return map(int, data().split())

n,m,p=mdata()
a=list(mdata())
b=list(mdata())
for i in range(min(n,m)):
    if a[i]%p!=0 or b[i]%p!=0:
        if a[i]%p!=0:
            if b[i]%p!=0:
                print(i+i)
            else:
                ind=0
                for j in range(i+1,m):
                    if b[j]%p!=0:
                        ind=j
                        break
                print(i+ind)
        else:
            ind=0
            for j in range(i+1,n):
                if a[j]%p!=0:
                    ind=j
                    break
            print(i+ind)
        break
