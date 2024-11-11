from math import *
from collections import *
from random import *
from decimal import Decimal
from bisect import *
import sys
#input=sys.stdin.readline
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
n,m=ma()
r=[[] for i in range(m)]
for i in range(n):
    s=st()
    for j in range(m):
        if(s[j] in r[j]):
            continue
        r[j].append(s[j])
re=1
p=1000000007
for i in r:
    re=re*len(i)
    re=re%p
print(re%p)
    
        
    
