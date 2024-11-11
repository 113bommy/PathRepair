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
			mini=min(mini,zero)
			if l==n:
				break

			if a[l]==0:
				zero-=1
			l+=1
		if r==n:
			break		
		if a[r]==0:
				zero+=1
		r+=1
		#print(l,r,mid,zero)	
	#print(mid,mini)	
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
l=r=zero=0
p=[0,n]
mini=n
while r<=n and l<=r:
		if r-l==ans:
			if zero<=mini:
				p=[l,r]
			mini=min(mini,zero)
			if l==n:
				break
			if a[l]==0:
				zero-=1
			l+=1
		if r==n:
			break		
		if a[r]==0:
				zero+=1
		r+=1
for i in range(p[0],p[1]):
	a[i]=1			
print(ans)	
print(*a)							

