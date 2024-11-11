from sys import stdin,stdout
from math import gcd,sqrt,factorial,pi,inf
from collections import deque,defaultdict
from bisect import bisect,bisect_left
from time import time
from itertools import permutations as per
from heapq import heapify,heappush,heappop,heappushpop
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\r\n')
L=lambda:list(R())
P=lambda x:stdout.write(str(x)+'\n')
lcm=lambda x,y:(x*y)//gcd(x,y)
nCr=lambda x,y:(f[x]*inv((f[y]*f[x-y])%N))%N
inv=lambda x:pow(x,N-2,N)
sm=lambda x:(x**2+x)//2
N=10**9+7

n,x,k=R()
a=sorted(R())
ans=0
val=x*k
for i in a:
	if k==0 and not i%x:
		continue
	p=i+x-i%x-1+val-(x if i%x==0 else 0)
	ans+=bisect(a,p)-bisect_left(a,max(i,p-(x-1)))
	#print(p)
print(ans)