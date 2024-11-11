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

x,y,l,r=R()
a={l-1,r+1}
p=[]
q=[]
v=1
while v<=r:
	p+=v,
	if x==1:
		break
	v*=x
v=1
while v<=r:
	q+=v,
	if y==1:
		break
	v*=y
for i in p:
	for j in q:
		if i+j>r:break
		if i+j>=l:
			a.add(i+j)
ans=0
a=sorted(a)
for i in range(1,len(a)):
	ans=max(ans,a[i]-a[i-1]-1)
print(ans)