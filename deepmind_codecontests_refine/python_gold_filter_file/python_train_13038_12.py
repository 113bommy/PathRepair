import math
import sys
input=sys.stdin.readline
t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    if m%2==0:
        print((n*(m//2)))
    else:
        print((n*(m//2))+math.ceil(n/2))
