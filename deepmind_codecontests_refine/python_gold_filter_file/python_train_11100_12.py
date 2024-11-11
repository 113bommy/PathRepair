z,zz=input,lambda:list(map(int,z().split()))
fast=lambda:stdin.readline().strip()
zzz=lambda:[int(i) for i in fast().split()]
szz,graph,mod,szzz=lambda:sorted(zz()),{},10**9+7,lambda:sorted(zzz())
from string import *
from re import *
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
    visit[u]=1
    for i in graph[u]:
        if not visit[i]:
            dfs(i,visit,graph)

###########################---Test-Case---#################################
"""



"""
###########################---START-CODING---##############################


quee=deque()

n,k=zzz()
quee.extend(zzz())


cnt=0
maxper=max(list(quee))
last_per=-1

while True:
    u=quee.popleft()
    v=quee.popleft()
    loser=min(u,v)
    win=max(u,v)
    if win==last_per:
        cnt+=1
    else:
        cnt=1
        last_per=win
    if cnt==k:
        break
    if win==maxper:
        break
    quee.append(loser)
    quee.appendleft(win)
print(last_per)



