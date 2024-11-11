for _ in range(int(input())):
	n=int(input());a=sorted(list(map(int,input().split())))
	print(min(a[n-2]-1,n-2))
#0 1 2 3 4 5