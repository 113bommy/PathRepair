import sys
from collections import defaultdict as dd

pl=1
from math import *
import copy
#sys.setrecursionlimit(10**6)
if pl:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('all.txt','w')
def li():
	return [int(xxx) for xxx in input().split()]
def fi():
	return int(input())
def si():
	return list(input().rstrip())	
def mi():
	return 	map(int,input().split())	
 

d=[]		
from bisect import *		

from itertools import permutations 
from collections import deque
def siv(n):
	prime = [True for i in range(n+1)] 
	p = 2
	if 1:
	    while (p * p <= n): 

	        if (prime[p] == True): 
	            for i in range(p * p, n+1, p): 
	                prime[i] = False
	        p += 1
	      
	 
	    for p in range(2, n+1): 
	        if prime[p]: 
	            d.append(p)

n,k=mi()
a=li()
def can(mid):
	mini=n
	l=r=zero=0
	while r<=n and l<=r:
		if r-l==mid:
			#print(l,r,mid,zero)
			mini=min(mini,zero)
			if a[l]==0:
				zero-=1
			l+=1
		if l==n or r==n:
			break	
		if a[r]==0:
			zero+=1
		r+=1		

	return mini<=k
l=0
r=n
ans=n
while l<=r:
	mid=(l+r)//2
	if can(mid):
		ans=mid
		l=mid+1
	else:
		r=mid-1
mini=n
p=[0,n]
l=r=zero=0
while r<=n and l<=r:
		if r-l==ans:

			if zero<mini:
				p=[l,r]
			mini=min(mini,zero)
			if a[l]==0:
				zero-=1
			l+=1
		if l==n or r==n: 
			break	
		if a[r]==0:
			zero+=1
		r+=1
		
for i in range(p[0],p[1]):
	a[i]=1			
print(ans)	
print(*a)							
