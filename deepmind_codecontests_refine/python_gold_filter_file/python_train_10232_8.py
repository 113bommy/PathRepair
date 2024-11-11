# Author : -pratyay-
import sys
inp=sys.stdin.buffer.readline
inar=lambda: list(map(int,inp().split()))
inin=lambda: int(inp())
inst=lambda: inp().decode().strip()
wrt=sys.stdout.write
pr=lambda *args,end='\n': wrt(' '.join([str(x) for x in args])+end)
enum=enumerate
inf=float('inf')
cdiv=lambda x,y: (-(-x//y))
# Am I debugging ? Check if I'm using same variable name in two places
# fun() returning empty list ? check new=temp[:] or new=temp

from heapq import *
_T_=inin()
for _t_ in range(_T_):
    n=inin()
    s=inst()
    '''if _t_==6:
        pr(s)'''
    a=[]
    prev='#'
    cnt=0
    for i in s:
        if i==prev:
            cnt+=1
        else:
            a.append(cnt)
            cnt=1
        prev=i
    a.append(cnt)
    a=a[1:]
    n=len(a)
    a.append(inf)
    takeout=0
    sol=0
    for i in range(n):
        while(a[takeout]==1):
            takeout+=1
        a[takeout]-=1
        if a[takeout]!=inf:
            sol+=1
        takeout=max(takeout,i+1)
        sol+=1
    pr(cdiv(sol,2))
