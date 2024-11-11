from sys import stdin,stdout
from math import gcd,sqrt,factorial,pi,inf
from collections import deque,defaultdict
from bisect import bisect,bisect_left
from time import time
from itertools import permutations as per
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

for _ in range(I()):
	n,l,r=R()
	if l==r==(n-1)*n+1:print(1);continue
	p=0
	for i in range(n-1,0,-1):
		p+=i*2
		if p>=l:
			k=n-i
			if l%2==0:
				x=(n-i)+(l-(p-i*2))//2
				print(x,end=' ')
				l+=1
				j=x+1
				if x==n:
					k+=1
					j=k+1
			else:
				j=(n-i)+(l+1-(p-i*2))//2
			for i in range(r-l+1):
				if i%2:
					print(j,end=' ')
					if j==n:
						j=k+1
						k+=1
					j+=1
				else:
					if k!=n:print(k,end=' ')
					else:print(1,end=' ')
			break
	print()