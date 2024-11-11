import sys
import collections as cc
import bisect as bi
I=lambda:list(map(int,input().split()))
for tc in range(int(input())):
	n,x,m=I()
	ans=1
	actx=10**9+10;acty=-10**9+10;
	f=0
	for i in range(m):
		l,r=I()
		if not f and x>=l and x<=r:
			ans+=abs(l-r)
			actx=l
			acty=r
			f=1
		elif f:
			if l>=actx and r<=acty:
				continue
			elif l<actx and r>acty:
				ans+=abs(l-actx)
				ans+=abs(r-acty)
				acty=r
				actx=l
			elif l<actx and r>=actx and r<=acty:
				ans+=abs(l-actx)
				actx=l
			elif r>acty and l>=actx and l<=acty:
				ans+=abs(r-acty)
				acty=r
	print(ans)





