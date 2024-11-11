# import sys
# sys.stdin = open("test.in","r")
# sys.stdout = open("test.out","w")
n,k=map(int,input().split())
if k%n==0:
	print(int(k/n))
else:
	print((k//n)+1)	