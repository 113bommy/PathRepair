t = int(input())
for _ in range(t):
	n = int(input())
	if n < 4:
		print('-1')
	else:
		evens = [2*x for x in range(1, (n//2+1))]
		odds = [x-1 for x in evens]
		if n%2 == 1:
			odds.append(n)
			evens[-1], evens[-2] = evens[-2], evens[-1]
		else:
			odds[-1], odds[-2] = odds[-2], odds[-1]
		evens.reverse()
		for i in odds:
			print(i, end = ' ')
		for i in evens:
			print(i, end = ' ')
		print('')
