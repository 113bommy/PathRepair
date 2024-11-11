from sys import stdin,stdout
import math
n,m,k,l=map(int,stdin.readline().split())
if m>n:
    print(-1)
elif l==0:
    print(0)
else:
    x=(l+k)//m
    if (l+k)%m!=0:
        x+=1
    if x*m>n:
        print(-1)
    else:
        print(x)
