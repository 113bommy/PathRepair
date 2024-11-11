t = int(input())
for i in range(t):
	n = int(input())
	a = input()
	com = a[n - 1]
	b = ""
	for i in range(n):
		b += com
	print(b)  