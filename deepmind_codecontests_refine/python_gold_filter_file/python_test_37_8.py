#from math import *
#from bisect import *
#from collections import *
#from random import *
#from decimal import *"""
#from heapq import *
#from itertools import *
import sys
input=sys.stdin.readline
def inp():
    return int(input())
def st():
    return input().rstrip('\n')
def lis():
    return list(map(int,input().split()))
def ma():
    return map(int,input().split())
t=inp()
while(t):
    t-=1
    n,m=ma()
    vis=[0]*n
    for i in range(m):
        a,b,c=ma()
        vis[b-1]=1
    c=vis.index(0)+1
    for i in range(n):
        if(i+1!=c):
            print(i+1,c)
        
