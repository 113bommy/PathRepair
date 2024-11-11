def q46a():
	n = int(input())
	current_holder = 1
	for i in range(1, n):
		current_holder += i
		print((current_holder-1) % n + 1, end=' ')
	print("")


q46a()