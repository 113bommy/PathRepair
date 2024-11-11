t = int(input())
for i in range(t):
	[n, K] = [int(i) for i in input().split()]
	s = input()
	arr = [s[i] for i in range(n)]
	ans = []
	for j in range(n // 2):
		if arr[j] != '(':
			k = j + 1
			while arr[k] != '(':
				k += 1
			ans.append([j + 1, k + 1])
			for l in range(0, (k - j + 1) // 2):
				d = arr[j + l]
				arr[j + l] = arr[k - l]
				arr[k - l] = d
	have = n // 2
	for j in range(K - 1):
		x = j * 2 + 1
		y = x + 1
		while arr[y] != ')':
			y += 1
		ans.append([x + 1, y + 1])
		for l in range(0, (y - x) // 2):
			d = arr[x + l]
			arr[x + l] = arr[y - l]
			arr[y - l] = d
	print (len(ans))
	for j in ans:
		print (j[0], j[1])