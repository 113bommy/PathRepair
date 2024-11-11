n=int(input())
l=sorted(list(map(int, input().split())))
a=[]
if n<=2:
	print(*l[::-1])
else:
	a.append(l[-1])
	a.append(l[0])
	a.append(l[-2])
	for i in range(n-3,0,-1):
		a.append(l[i])
	print(*a)
	