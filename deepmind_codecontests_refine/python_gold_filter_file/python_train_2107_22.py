from sys import stdin
input=lambda : stdin.readline()
from math import ceil
for _ in range(int(input())):
	n=int(input())
	l=list(map(int,input().split()))
	z=[]
	for i in range(n):
		if i%2:
			z.append(1)
		else:
			z.append(2)
	if len(set(l))==1:
		print(1)
		print('1 '*n)
	elif n%2==0 or l[0]==l[-1]:
		print(2)
		print(*z)
	else:
		flag=0
		for i in range(1,n):
			if l[i]==l[i-1]:
				k=i
				flag=1
		if flag:
			print(2)
			print(*z[:k],z[k-1],*z[k:-1])
		else:
			print(3)
			print(*z[:-1],3)