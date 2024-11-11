import math as mt 
import sys,string,bisect
input=sys.stdin.readline
from collections import deque,defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
t=I()
for _ in range(t):
    k,n,a,b=M()
    just=(k-1)//a
    if(just>=n):
        print(n)
    else:
        y=mt.ceil((a*n-k+1)/(a-b))
        x=n-y
        if k-(x*a+y*b)<=0:
            print(-1)
        else:
            if(x<0):
                print(-1)
            else:
                print(x)
        
