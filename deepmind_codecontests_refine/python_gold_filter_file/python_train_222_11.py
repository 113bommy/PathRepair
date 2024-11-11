a = int (input())
b = input()
nulls = b.count("0")
ones = b.count("1")
if (nulls==ones):
	print(2)
	print(b[0] + " " + b[1:])
else:
	print(1)
	print(b)		

