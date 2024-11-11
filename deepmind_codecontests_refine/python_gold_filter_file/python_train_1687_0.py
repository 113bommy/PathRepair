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

def get_ans(x):
	ans=0
	for i in range(p):
		#print(i+(x-(i+1)%x)%x-x//2)
		ans+=abs(ind[i+(x-(i+1)%x)%x-x//2]-ind[i])
	return ans

n=I()
a=L()
p=cnt=a.count(1)
if cnt==1:exit(print(-1))
ans=inf
ind=[i for i in range(n) if a[i]]
for i in range(2,int(sqrt(cnt))+1):
	if not cnt%i:
		ans=min(ans,get_ans(i))
		while not cnt%i:
			cnt//=i
if cnt!=1:ans=min(ans,get_ans(cnt))
print(ans)