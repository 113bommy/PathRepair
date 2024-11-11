z,zz=input,lambda:list(map(int,z().split()));
szz,graph,mod=lambda:sorted(zz()),{},10**9+7
zzz=lambda:[int(i) for i in stdin.readline().split()]
from string import *
from collections import *
from queue import *
from sys import *
from collections import *
from math import *
from heapq import *
from itertools import *
from bisect import *
from collections import Counter as cc
from math import factorial as f
from bisect import bisect as bs
from bisect import bisect_left as bsl
from itertools import accumulate as ac
def lcd(xnum1,xnum2):return (xnum1*xnum2//gcd(xnum1,xnum2))
def prime(x):
    p=ceil(x**.5)+1
    for i in range(2,p):
        if (x%i==0 and x!=2) or x==0:return 0
        
    return 1
def dfs(u,visit,graph):
    visit[u]=True
    for i in graph[u]:
        if not visit[i]:
            dfs(i,visit,graph)

###########################---Test-Case---#################################
"""

3
3
120
5
11011
6
600005

"""
###########################---START-CODING---##############################


num=int(z())

for _ in range( num ):
    n=int(z())
    l=list(ac(list(map(int,z()))))
    ans=0
    li=[1]+[0]*(9*n+1)

    for i in range(n):
        p=l[i]
        ans+=li[p-i-1]
        li[p-i-1]+=1
    print(ans)
    
            











