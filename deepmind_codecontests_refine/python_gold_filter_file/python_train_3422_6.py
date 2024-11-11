import sys
import math as mas

li='abcdefghijklmnopqrstuvwxyz'
for t in sys.stdin:
	for i in range(30):
		a=t[:-1].translate(str.maketrans(li,li[i:]+li[:i]))
		if 1+a.find("this") or 1+a.find("that") or 1+a.find("the"):
			print(a)
			break
#for i in sys.stdin:
#	a,b=map(int,i.split())
#	print(gcd(a,b),lcm(a,b))