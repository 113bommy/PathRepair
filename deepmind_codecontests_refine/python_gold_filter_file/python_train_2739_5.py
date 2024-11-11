import sys,os,io
import bisect
from random import random
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
 
n,q = [int(i) for i in input().split()]
a = [int(i)-1 for i in input().split()]
ind = [[] for i in range (n)]
for i in range (len(a)):
    ind[a[i]].append(i)
 
for i in range (q):
    flag = 0
    l,r = [int(i)-1 for i in input().split()]
    rem = r-l+1
    total = rem
    total2 = (total+1)//2
    vis = set()
    for j in range (25):
        rand = int(random()*(total)) + l
        ele = a[rand]
        if ele in vis:
            continue
        vis.add(ele)
        if len(ind[ele])<= total2:
            continue
        right = bisect.bisect(ind[ele], r)
        left = bisect.bisect_left(ind[ele],l)
        cnt = right - left
        if cnt>total2:
            flag = cnt
            break
        rem -= cnt
        if rem<=total2:
            break
    if flag:
        print(2*flag - total)
    else:
        print(1)