import math as mt 
import sys,string
input=sys.stdin.readline
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda :int(input())
from collections import defaultdict

n=I()
if(n<3):
    print(-1)
elif(n==3):
    print(210)
else:
    x=[50,80,170,20,200,110]
    print('1'+'0'*(n-1-len(str(x[(n-4)%6])))+str(x[(n-4)%6]))
    
