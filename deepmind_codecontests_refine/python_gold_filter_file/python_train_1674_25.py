while True:
	(x,y)=[int(i) for i in input().split()]
	if x==y==0:break
	print("#"*y)
	for i in range(1,x-1):
		print("#"+"."*(y-2)+"#")
	print("#"*y)
	print()