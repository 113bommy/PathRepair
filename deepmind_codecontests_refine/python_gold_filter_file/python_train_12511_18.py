import sys
import os.path
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log
if os.path.exists('input.txt'):
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')

n,m=map(int,input().split())

cnt,sum,ans=2,1,0

while n>0:
    #print(sum, end= " ")
    if sum>m:
        ans=ans + sum-m
        n=n- (sum-m)
        sum=m
    else:
        sum=sum+cnt
        n=n-1
        cnt=cnt+1
print(ans)        
