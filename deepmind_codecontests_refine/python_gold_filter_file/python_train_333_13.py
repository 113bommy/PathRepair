from sys import stdin,stdout
from math import gcd,sqrt,inf
from collections import deque
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\n')
L=lambda:list(R())
P=lambda x:stdout.write(x)
hg=lambda x,y:((y+x-1)//x)*x
pw=lambda x:1 if x==1 else 1+pw(x//2)
chk=lambda x:chk(x//2) if not x%2 else True if x==1 else False
N=inf
n,k=R()
a=[deque() for i in range(2*10**5+7)]
v=[0]*(2*10**5+7)
sm=[0]*(2*10**5+7)
for i in sorted(R(),reverse=True):
	a[i].appendleft(0)
	v[i]+=1
	if v[i]>k:
		v[i]=k
		sm[i]-=a[i].pop()
	stp=0
	while i:
		i//=2
		stp+=1
		a[i].appendleft(stp)
		v[i]+=1
		sm[i]+=stp
		if v[i]>k:
			sm[i]-=a[i].pop()
			v[i]=k
ans=inf
for i in range(2*10**5+7):
	if v[i]==k:ans=min(sm[i],ans)
print(ans)