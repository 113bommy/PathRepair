import sys
import math
def II():
	return int(sys.stdin.readline())

def LI():
	return list(map(int, sys.stdin.readline().split()))

def MI():
	return map(int, sys.stdin.readline().split())

def SI():
	return sys.stdin.readline().strip()
t = II()
for q in range(t):
	n = II()
	l = LI()
	m = 0
	s = 0
	su = 0
	for i in range(n):
		if i%2 == 0:
			su+=l[i]
	for i in range(0,n-1,2):
		s+=l[i+1]-l[i]
		if s>m:
			m = s
		elif s<0:
			s = 0
	s = 0
	for i in range(2,n,2):
		s+=l[i-1]-l[i]
		if s>m:
			m = s
		elif s<0:
			s = 0
	print(su+m)
