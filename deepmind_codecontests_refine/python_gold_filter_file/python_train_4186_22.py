for _ in range(int(input())):
	n = int(input())
	rooms = list(map(int, list(input())))

	no1 = sum(rooms)
	if no1 == 0:
		print(n)
		continue

	if no1 == 1:
		ind = rooms.index(1) 
		if n%2 == 1 and ind == n // 2:
			print(2*(ind + 1))
		else:
			if ind < n // 2:
				print(2*(n - ind))
			else:
				print(2*(ind + 1))
		continue

	for i in range(n):
		if rooms[i]:
			start = i
			break
	for i in range(n-1, -1, -1):
		if rooms[i]:
			end = i
			break
	
	if start == 0 or end == n-1:
		print(2*n)
	else:
		if (start + 1) > (n - end):
			print(2*(end+1))
		else:
			print(2*(n - start))
	

