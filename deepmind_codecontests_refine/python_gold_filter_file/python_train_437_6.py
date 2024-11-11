t=int(input())
for _ in range(0,t):
	n=int(input())
	a=list(map(int,input().split()))
	a.sort()
	a=set(a)
	print(len(a))