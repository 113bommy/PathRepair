import math as mt 
import sys,string,bisect
input=sys.stdin.readline
import random
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
d=defaultdict(int)
x="abcdefghijklmnopqrstuvwxyz"
t=I()
for _ in range(t):
    n,a,b=M()
    p=x[:b]
    i=0
    while(len(p)<n):
        p+=p[i]
        i+=1
    print(p)
    
