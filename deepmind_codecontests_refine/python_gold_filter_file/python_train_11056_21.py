for _ in range (int(input())):
	x, y = map(int, input().split())
	f = True
	if x == 1 and y != 1:
		f = False
	if (x == 2 or x == 3) and (y >= 4):
		f = False
	if f == True:
		print("yes")
	else:
		print("NO")