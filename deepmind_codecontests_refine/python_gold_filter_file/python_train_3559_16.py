from sys import stdin,stdout
from math import gcd,sqrt,factorial,pi
from collections import deque,defaultdict
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
sm=lambda x:(x**2+x)//2
N=10**9+7

def get_val(n):
	i=0
	while n:
		i+=(n&1)
		n>>=1
	return i

n,k=R()
k*=-1
p=0
if k==0:
	exit(print(get_val(n)))
while n:
	p+=1
	n+=k
	if n<=0:exit(print(-1))
	if get_val(n)<=p<=n:exit(print(p))