import sys
import math
 
def read_line():
	return sys.stdin.readline()[:-1]
 
def read_int():
	return int(sys.stdin.readline())
 
def read_int_line():
	return [int(v) for v in sys.stdin.readline().split()]

t = read_int()
for i in range(t):
	a,b = read_int_line()
	if a==b:
		print(0)
	else:
		if a<b:
			if a%2==0 and b%2==0:
				print(2)
			elif a%2==0 and b%2!=0:
				print(1)
			elif a%2!=0 and b%2==0:
				print(1)
			elif a%2!=0 and b%2!=0:
				print(2)
		else:
			if a%2==0 and b%2==0:
				print(1)
			elif a%2==0 and b%2!=0:
				print(2)
			elif a%2!=0 and b%2==0:
				print(2)
			elif a%2!=0 and b%2!=0:
				print(1)