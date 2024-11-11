for nt in range(int(input())):
	n=int(input())
	a=list(map(int,input().split()))
	b=list(map(int,input().split()))
	print (*sorted(a))
	print (*sorted(b))