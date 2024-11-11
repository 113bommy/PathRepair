import sys, os.path
from collections import*
from copy import*
import math
mod=10**9+7
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r")
    sys.stdout = open("output.txt","w")


n,s=map(int,input().split())
mat=[]
buy={}
sell={}
for i in range(n):
    dpq=list(map(str,input().split()))
    d=dpq[0]
    p=int(dpq[1])
    q=int(dpq[2])
    if(d=="S"):
        sell[p]=sell.get(p,0)+q
    else:
        buy[p]=buy.get(p,0)+q
b=list(buy.items())
b.sort()
sel=list(sell.items())
sel.sort()
b=b[-s:]
sel=sel[:s]
b.reverse()
sel.reverse()
for i in sel:
    print('S',*i)
for i in b:
    print('B',*i)





