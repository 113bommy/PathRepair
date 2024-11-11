from math import inf as inf
from math import *
from collections import *
import sys
from itertools import permutations
input=sys.stdin.readline
t=1
while(t):
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    s=0
    c=[0]*20
    for i in a:
        for j in range(20):
            c[j]+=(i>>j)&1
    for i in range(n):
        te=0
        for j in range(20):
            if(c[j]):
                c[j]-=1
                te+=(1<<j)
        s+=te*te
    print(int(s))
            
