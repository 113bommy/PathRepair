n = int(input())

if n <= 3:
	print("NO")
elif n == 5:
	print("YES")
	print("5 - 2 = 3")
	print("3 - 1 = 2")
	print("4 * 3 = 12")
	print("12 * 2 = 24")
else:
	print("YES")
	print("4 * 3 = 12")
	print("12 * 2 = 24")
	
	counter = 0
	if (n % 2 == 0):
		for i in range(5, n, 2):
			print(i+1,"-",i,"= 1")
			counter += 1
		for i in range(counter):
			print("1 * 1 = 1")
		print("24 * 1 = 24\n")
	else:
		print("6 - 5 = 1")
		print("1 - 1 = 0")
		for i in range(7, n+1):
			print(i, "* 0 = 0")
		print("24 + 0 = 24\n")