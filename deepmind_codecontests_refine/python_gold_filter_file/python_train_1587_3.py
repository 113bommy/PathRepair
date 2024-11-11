import os, sys, bisect, copy
from collections import defaultdict, Counter, deque
from functools import lru_cache   #use @lru_cache(None)
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')
#
def input(): return sys.stdin.readline()
def mapi(arg=0): return map(int if arg==0 else str,input().split())
#------------------------------------------------------------------

spf = [0]*500005
def sieve():
    spf[1]=1
    for i in range(2,500005): spf[i]=i
    for i in range(4,500005,2): spf[i]=2
    for i in range(3,int(500005**.5)+1):
        if spf[i]==i:
            for j in range(i*i, 500005, i):
                if spf[j]==j: spf[j]=i
sieve()
n = int(input())
res = []
for i in range(2,n+1):
    res.append(i//spf[i])
res.sort()
print(*res)