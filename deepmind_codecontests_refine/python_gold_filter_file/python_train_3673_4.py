for _ in range(int(input())):

	n = int(input())
	s = input()
	cnt = 0
	visited = [False] * n
	bakar = None
	for i in range(n):
		left = i - 1
		right = i
		if left == -1:
			left = n - 1
		if s[left] == '-' or s[right] == '-':
			cnt += 1
		else:
			bakar = i
	i = 0
	while i < n:
		if s[i] == '>' or s[i] == '-':
			i += 1
		else:
			break
	if i == n:
		cnt = n
	i = n - 1
	while i >= 0:
		if s[i] == '<' or s[i] == '-':
			i -= 1
		else:
			break
	if i == -1:
		cnt = n
	print(cnt)
