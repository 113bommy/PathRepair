import math
from sys import stdin
from sys import setrecursionlimit
setrecursionlimit(100000)
def put():  return  map(int, stdin.readline().split())
for _ in range(1):
	# n=int(input())
	n=int(input())
	a1,a2,a3=put()
	b1,b2,b3=put()
	mx=min(a1,b2)+min(a2,b3)+min(a3,b1)
	mn=n
	if(a1<=b3):
		mn-=min(a1,b3)
		a1=0
		b3-=a1
	else:
		mn-=min(a1,b3)
		b3=0
		a1-=b3
	if(a2<=b1):
		mn-=min(a2,b1)
		a2=0
		b1-=a2
	else:
		mn-=min(a2,b1)
		b1=0
		a2-=b1
	if(a3<=b2):
		mn-=min(a3,b2)
		a3=0
		b2-=a3
	else:
		mn-=min(a3,b2)
		b2=0
		a3-=b2
	print(max(0,mn-min(a1,b1)-min(a2,b2)-min(a3,b3)),mx)