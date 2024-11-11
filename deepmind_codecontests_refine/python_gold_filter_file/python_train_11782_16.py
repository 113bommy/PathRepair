for i in range(int(input())):
	k, n, a, b =list(map(int, input().split()))
	left = k - n *b
	if left <= 0:
		print(-1)
	else:
		print(min(left // (a-b) - 1 * int((left % (a-b)) == 0) , n))