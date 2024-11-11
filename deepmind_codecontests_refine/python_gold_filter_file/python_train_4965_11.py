#      Codeforces Round #491 (Div. 2)
import collections
from functools import cmp_to_key
#key=cmp_to_key(lambda x,y: 1 if x not in y else -1 )
import math
import sys
def getIntList():
    return list(map(int, input().split()))    

import bisect 
try :
    import numpy
    dprint = print
    dprint('debug mode')
except ModuleNotFoundError:
    def dprint(*args, **kwargs):
        pass
def makePair(z):
    return  [(z[i], z[i+1]) for i in range(0,len(z),2) ]


 
n, = getIntList()


def work(k,n):
    a = 0
    b = 0
    while(n>0):
        a += min(n,k)
        if n<=k:
            break
        n-=k
        t =  n//10 
        b +=t
        n-=t
    if a>=b:
        return True
    return False


r0 = 0
r1 = n

while r0+1<r1 :
    m = (r0+r1)//2
    if work(m,n):
        r1 = m
    else :
        r0 = m

print(r1)

    

    
