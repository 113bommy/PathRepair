from sys import stdin,stdout
input=stdin.readline 
import math,bisect

n,v=map(int,input().split())
l=[0]*(3002)
for i in range(n):
	a,b=map(int,input().split())
	l[a]+=b

ans=0
rem=0
for i in range(1,3002):
	if l[i]+rem<=v:
		ans+=(l[i]+rem)
		rem=0
	else:
		if rem>=v:
			ans+=v
			rem=l[i]
		else:
			ans+=rem
			if l[i]>=v-rem:
				ans+=v-rem
				rem=l[i]-(v-rem)
			else:
				ans+=l[i]
				rem=0
print(ans+min(v,rem))

