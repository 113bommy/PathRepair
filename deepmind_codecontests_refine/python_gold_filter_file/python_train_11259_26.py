from bisect import bisect_right as br
from bisect import bisect_left as bl
from collections import *
from itertools import *
import functools
import sys
import math
import random
import re
MAX = sys.maxsize
MAXN = 10**5+10
MOD = 10**9+9
def isprime(n):
    n = abs(int(n))
    if n < 2:
        return False
    if n == 2: 
        return True    
    if not n & 1: 
        return False
    for x in range(3, int(n**0.5) + 1, 2):
        if n % x == 0:
            return False
    return True

def mhd(a,b,x,y):
    return abs(a-x)+abs(b-y)

def numIN(x = " "):
    return(map(int,sys.stdin.readline().strip().split(x)))

def charIN(x= ' '):
    return(sys.stdin.readline().strip().split(x))

def dis(x,y):
    a = y[0]-x[0]
    b = x[1]-y[1]
    return (a*a+b*b)**0.5

def lgcd(a):
    g = a[0]
    for i in range(1,len(a)):
        g = math.gcd(g,a[i])
    return g

def ms(a):
    msf = -MAX
    meh = 0

    for i in range(len(a)):
        meh+=a[i]
        if msf<meh:
            msf = meh
        if meh<0:
            meh = 0
    return msf


def res(ans,t):
    print('Case #{}: {}'.format(t,ans))



def chk(x,t):
    a = x[0]
    d = x[1]
    n = math.ceil(((t-a)/d)+1)

    return (a+(n-1)*d)


n,t = numIN()
l = [0]

for _ in range(n):
    a,b = numIN()
    l.append([a,b])
a = [MAX]
for i in range(1,n+1):
    if l[i][0]<t:
        a.append(chk(l[i],t))
    else:
        a.append(l[i][0])

print(a.index(min(a)))






