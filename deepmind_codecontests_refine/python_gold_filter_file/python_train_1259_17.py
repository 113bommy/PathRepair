n = int(input())
for h in range(n):
	m = int(input())
	x = input()
	ji = 0
	for i in range(m):
		if x[i]!=x[m-1-i] and abs(ord(x[i])-ord(x[m-1-i])) != 2:
			ji = 1
			break
	print('NO' if ji else 'YES')