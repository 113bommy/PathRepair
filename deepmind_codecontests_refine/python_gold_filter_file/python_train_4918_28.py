for _ in range(int(input())):
	n,a,b = map(int,input().split())
	ans = []
	index=0
	while (index <=n):
		for i in range(b):
			ans.append(chr(97+i))
		index += b
		if ( n - index < b):
			for i in range(n - index):
				ans.append(chr(97+i))
			break
	print("".join(ans))