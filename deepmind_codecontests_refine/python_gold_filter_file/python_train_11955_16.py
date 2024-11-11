from bisect import *
from collections import *
from fractions import gcd
from math import factorial
from itertools import *
from heapq import *
import copy

N,M=map(int,input().split())
A=list(map(int,input().split()))
XY=[list(map(int,input().split())) for i in range(M)]
data=[[] for i in range(N)]

for x,y in XY:
    data[x].append(y)
    data[y].append(x)
visitedlst=[]

ittenai=set([i for i in range(0,N)])
while ittenai:
    q=ittenai.pop()
    stack=[q]
    visited=set()
    visited.add(q)
    while stack:
        q=stack.pop()
        for p in data[q]:
            if p not in visited:
                visited.add(p)
                ittenai.remove(p)
                stack.append(p)
    visitedlst.append(visited)
lst=[]
value=0
count=0
for visited in visitedlst:
    visited=sorted([A[i] for i in list(visited)])
    for i in visited[1:]:
        lst.append(i)
    value+=visited[0]
    count+=1
if count==1:
    print(0)

elif len(lst)<(count//2-1)*2+count%2:
    print("Impossible")
else:
    lst.sort()
    value+=sum(lst[:(count//2-1)*2+count%2])
    print(value)
