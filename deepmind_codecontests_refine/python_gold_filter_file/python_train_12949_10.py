# import sys
# sys.stdin=open("input.in","r")
n=int(input())
l=list(map(int,input().split()))
f=min(l)
c=0
if 1 in l:
	print("1")
	exit(0)
else:
	for i in range(n):
		if l[i]%f==0:
			c+=1
if c==n:
	print(f)
else:
	print("-1")