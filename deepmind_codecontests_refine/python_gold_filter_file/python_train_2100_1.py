from sys import stdin,stdout
from bisect import bisect_right as br
from bisect import bisect_left as bl
from bisect import insort_left as il
from math import gcd

n,m=map(int,stdin.readline().split())
ship=[int(i) for i in stdin.readline().split()]
lst=[[-1,0]]
for i in range(m):
    a,b=map(int,stdin.readline().split())
    lst+=[[a,b]]
lst.sort()
temp=lst[0]
for i in lst[1:]:
    i[1]+=temp[1]
    temp=i
for i in ship:
    stdout.write(str(lst[br(lst,[i,10**18])-1][1])+' ')
