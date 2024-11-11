import sys
input = sys.stdin.readline
import math
import copy
import collections
from collections import deque
inf = 10**18

n,m = list(map(int,input().split()))
arr = []
for i in range(n):
    arr.append(list(map(int,input().split())))
ans = 0
for i in range(m):
    vals = []
    for j in range(n):
        if arr[j][i]>=i+1 and arr[j][i]<=(i+1)+(m*(n-1)) and (arr[j][i]-(i+1))%m==0:
            vals.append(-(arr[j][i]-((i+1)+(m*j)))//m%n)
        else:
            vals.append(10**18)
    counts = dict()
    for val in vals:
        if val not in counts:
            counts[val] = 0
        counts[val]+=1
    total = 0
    for num in counts:
        total+=counts[num]
    add = 10**18
    for num in counts:
        if num==10**18:
            continue
        temp = num+total-counts[num]
        add = min(add,temp)
    ans+=min(add,n)
print(ans)
    