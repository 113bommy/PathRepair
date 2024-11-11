for _ in range(int(input())):
	n=int(input())
	arr=list(map(int,input().split()))
	l=set(arr)
	if len(l)==1:
		print(n)
	else:
		print(1)
