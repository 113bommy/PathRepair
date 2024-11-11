from sys import stdin,stdout
from math import gcd,sqrt
from collections import deque
input=stdin.readline
R=lambda:map(int,input().split())
I=lambda:int(input())
S=lambda:input().rstrip('\n')
L=lambda:list(R())
P=lambda x:stdout.write(x)
lcm=lambda x,y:(x*y)//gcd(x,y)
hg=lambda x,y:((y+x-1)//x)*x
pw=lambda x:1 if x==1 else 1+pw(x//2)
chk=lambda x:chk(x//2) if not x%2 else True if x==1 else False
dgnl=lambda x:sqrt(2*x**2)
for _ in range(I()):
	n=I()
	a=L()
	if n&1:a+=0,
	ans=0
	cur=0
	prf=0
	for i in range(0,n,2):
		prf+=a[i+1]-a[i]
		if i:cur+=a[i-1]-a[i]
		if prf<0:prf=0
		if cur<0:cur=0
		ans=max(ans,prf,cur)
	print(sum([a[i] for i in range(0,n,2)])+ans)