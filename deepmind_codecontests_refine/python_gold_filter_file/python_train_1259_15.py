# import sys 
# sys.stdin=open("input.in",'r')
# sys.stdout=open("out.out",'w')
from math import ceil as c
t=int(input())
for i in range(t):
	n=int(input())
	a=list(map(ord,input()))
	x=c(n/2)
	for i in range(x):
		if a[i]==a[n-1-i] or abs(a[i]-a[n-1-i])==2:
			flag=0
		else:
			flag=1
			break
	if flag:
		print("NO")
	else:
		print("YES")
