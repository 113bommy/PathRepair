for _ in range(int(input())):
	n = int(input())
	l =list(map(int, input().split()))
	l.sort()
	mini = 10000
	for i in range(n-1):
		m = l[i+1]-l[i]
		if m<mini:
			mini = m
	print(mini)
