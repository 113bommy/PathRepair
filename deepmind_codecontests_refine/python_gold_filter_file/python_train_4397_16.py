a=int(input())
for i in range(a):
	c=int(input())
	l=list(map(int,input().split()))
	y=list(map(int,input().split()))
	l.sort()
	y.sort()
	print(*l)
	print(*y)