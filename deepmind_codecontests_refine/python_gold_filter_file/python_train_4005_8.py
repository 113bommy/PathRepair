from sys import stdin
# input=stdin.buffer.readline
input=lambda : stdin.readline().strip()
lin=lambda :list(map(int,input().split()))
iin=lambda :int(input())
main=lambda :map(int,input().split())
from math import ceil,sqrt,factorial,log
from collections import deque
from bisect import bisect_left
mod=998244353
mod=1000000007
def gcd(a,b):
	a,b=max(a,b),min(a,b)
	while a%b!=0:
		a,b=b,a%b
	return b
def moduloinverse(a):
	return(pow(a,mod-2,mod))
def solve(we):
	a,b=main()
	ab=bin(a)[2:]
	bb=bin(b)[2:]
	if len(ab)<len(bb):
		x=int('1'*len(bb),2)
		# print('1'*(len(ab)-1))
		y=int('1'*(len(bb)-1),2)
		if x<=b:
			print(x)
		else:
			print(y)
	else:
		ans=''
		t=len(ab)
		for i in range(len(ab)):
			t-=1
			if bb[i]==ab[i]:
				ans+=bb[i]
			else:
				if i==len(ab)-1:
					ans+=bb[i]
				else:
					ans+='0'+'1'*t
					break
		if ans.count('1')>=bb.count('1'):
			print(int(ans,2))
		else:
			print(b)



qwe=1
qwe=iin()
for _ in range(qwe):
	solve(_+1)