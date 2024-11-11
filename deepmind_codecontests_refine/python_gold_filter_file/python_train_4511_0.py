for nt in range(int(input())):
	n = int(input())
	if n%2==0:
		ans = []
		for i in range(1, n, 2):
			ans.append(i+1)
			ans.append(i)
		print (*ans)
	else:
		ans = [3, 1, 2]
		for i in range(4, n+1, 2):
			ans.append(i+1)
			ans.append(i)
		print (*ans)