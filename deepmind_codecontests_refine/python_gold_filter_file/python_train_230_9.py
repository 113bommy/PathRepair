from collections import *
from bisect import *
from math import *
from heapq import *
import sys
input=sys.stdin.readline
t=int(input())
while(t):
    t-=1
    n=int(input())
    cir=pi/(4*n)
    s=1/(2*(sin(cir)))
    print(s)
    continue
    if(n%2):
        q=n//2
    else:
        q=(n//2)-1
    q=q*(360/(2*n))
    q=(q*pi)/180
    si=sin(q)
    si=si*si
    co=pow(1-si,0.5)
    d=2*s*s
    d*=(1-co)
    c=d/2
    c=pow(c,0.5)
    print(1+(2*c))
