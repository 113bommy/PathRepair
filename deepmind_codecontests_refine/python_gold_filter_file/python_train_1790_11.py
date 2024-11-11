#import sys
#sys.stdin=open("input.in","r")
#sys.stdout=open("test.out","w")
for i in range(int(input())):
	n=int(input())
	if n==2:
		print(2)
	elif n%2:
		print(1)
	else:
		print(0)