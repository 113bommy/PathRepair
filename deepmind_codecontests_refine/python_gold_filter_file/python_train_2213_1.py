import sys, math
import io, os
#data = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
#from bisect import bisect_left as bl, bisect_right as br, insort
#from heapq import heapify, heappush, heappop
from collections import defaultdict as dd, deque, Counter
#from itertools import permutations,combinations
def data(): return sys.stdin.readline().strip()
def mdata(): return list(map(int, data().split()))
def outl(var) : sys.stdout.write(' '.join(map(str, var))+'\n')
def out(var) : sys.stdout.write(str(var)+'\n')
#from decimal import Decimal
from fractions import Fraction
#sys.setrecursionlimit(100000)
#INF = float('inf')
mod = int(1e9)+7

n,m=mdata()
x,k,y=mdata()
a=mdata()
b=mdata()
ind=0
m1=0
l=[b[0]]
l1=[-1]
for i in range(n):
    if ind<m:
        if a[i]==b[ind]:
            l.append(m1)
            m1=b[ind]
            l1.append(i)
            ind+=1
    m1=max(m1,a[i])
l1.append(n)
l.append(m1)
if len(l1)!=m+2:
    out(-1)
    exit()
ans=0
if Fraction(x,k)<Fraction(y,1):
    for i in range(m+1):
        t=l1[i+1]-l1[i]-1
        m1 = 0
        if i > 0:
            m1 = a[l1[i]]
        if i < m:
            m1 = max(m1, a[l1[i + 1]])
        if t<k:
            if l[i + 1] > m1:
                out(-1)
                exit()
            else:
                ans+=y*t
        else:
            ans+=(t//k)*x+(t%k)*y
else:
    for i in range(m+1):
        t=l1[i+1]-l1[i]-1
        m1=0
        if i>0:
            m1=a[l1[i]]
        if i<m:
            m1=max(m1,a[l1[i+1]])
        if l[i+1]>m1:
            if t<k:
                out(-1)
                exit()
            else:
                ans+=x+(t-k)*y
        else:
            ans+=t*y
out(ans)
