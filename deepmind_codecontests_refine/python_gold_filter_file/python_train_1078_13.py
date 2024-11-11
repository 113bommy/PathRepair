n = int(input())
if n < 3:
	print(-1)
elif n == 3:
	print(210)
else:
	x = 7-[1, 3, 2, 6, 4, 5][(n-1)%6]
	if x%2 == 1:
		x += 7
	while (x+1)%3 != 0 or x%5 != 0:
		x += 14
	print(10**(n-1)+x)
