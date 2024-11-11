import os
from math import*

t=int(input())
while t:
	t-=1
	n,k=map(int,input().split())
	s=input()
	ans=0
	z=0
	count=0
	for i in range(n):
		if s[i]=="1":
			if z==0:
				ans+=count//(k+1)
				z=1
			else:
				c=count-k-k
				if c<=0:
					ans+=0
				elif c<k:
					ans+=1
				else:
					ans+=(1+(c-1)//(k+1))
			count=0
		else:
			count+=1
	if "1" not in s:
		if len(s)<=k:
			print("1")
		else:
			print(1+(n-1)//(k+1))
	else:
		print(ans+(count//(k+1)))