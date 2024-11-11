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
	a = LI()
	if len(set(a)) == 1:
		print(0)
	else:
		d = [0]*(10**5+1)
		m = 0
		for i in a:
			d[i]+=1
			m = max(m,d[i])
		if m == 2:
			print(len(set(a))-1)
		else:
			s = d.count(m)
			n -= s*m
			print(n//(m-1)+s-1)