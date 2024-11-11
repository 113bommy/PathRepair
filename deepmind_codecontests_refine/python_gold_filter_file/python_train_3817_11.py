x = int(input())
a = list(input())
if a.count("1") == 0:
	print("0")
else:
	a.sort(reverse=True)
	print("1"+a.count("0")*"0")