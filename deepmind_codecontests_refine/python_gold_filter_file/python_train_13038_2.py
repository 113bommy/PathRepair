from math import *
from collections import *
from itertools import *
from bisect import *
from heapq import *
from operator import *
from sys import *
setrecursionlimit(1000000)
d=defaultdict(lambda:0,{})
def io():
    return map(int,input().split())
def op():
    return list(map(int,input().split()))
def o():
    return int(input())
def l(x):
    return len(x)
def r(x):
    if type(x)==int:
        return range(x)
    else:return range(len(x))
def kl(con,x=0):
    if x==0:print('Yes') if con else print('No')
    elif x==1:print('yes') if con else print('no')
    elif x==2:print('YES') if con else print('NO')
MOD = 1000000007
MAX=float('inf')
MIN=-float('inf')
p=input
for _ in range(o()):
    a,b=io()
    c=b//2
    ans=0
    ans+=a*c
    ans+=(b%2)*(a+1)//2
    print(ans)