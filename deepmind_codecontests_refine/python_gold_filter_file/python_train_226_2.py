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
n,m = MI()
a = LI()
b = sorted(LI())
if a == b:
	print(0)
else:
	c = [(b[i]-a[0])%m for i in range(n)]
	for i in sorted(c):
		s = [(a[j]+i)%m for j in range(n)]
		if sorted(s) == b:
			print(i)
			break