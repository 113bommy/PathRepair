import sys
#from math import *
def eprint(*args):
    print(*args, file=sys.stderr)
zz=1
if zz:
	input=sys.stdin.readline
else:	
	sys.stdin=open('input.txt', 'r')
	sys.stdout=open('output2.txt','w')
t=int(input())
while t>0:
	t-=1	
	n,k=map(int,input().split())
	a=[int(x) for x in input().split()]
	if len(set(a))>k:
		print(-1)
		continue
	s=list(set(a))
	for i in range(k-len(s)):
		s.insert(0,1)
	print(n*len(s))
	for i in range(n):
		print(*s,end=" ")
	print()		