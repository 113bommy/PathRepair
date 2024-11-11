for i in range(int(input())):
	n,k = map(int,input().split())
	while k-1 and min(str(n))!="0":
		r = str(n)
		k-=1
		n = n+int(min(r))*int(max(r))

	print(n)
