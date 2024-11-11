import sys
input=sys.stdin.readline
from collections import *
from math import *
t=int(input())
while(t):
    t-=1
    n=int(input())
    flag=0
    p,c=map(int,input().split())
    if(c>p):
        flag=1
    for i in range(n-1):
        x,y=map(int,input().split())
        if(x>=p and y>=c and y<=x and (y-c)<=(x-p)):
            p=x
            c=y
            continue
        flag=1
    if(flag==0):
        print("YES")
    else:
        print("NO")
