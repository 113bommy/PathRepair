t = input()
ccwpos = ["> ^","< v","^ <","v >"]
cwpos = ["< ^","^ >","> v","v <"]
n = int(input())
if t in ccwpos:
	if (n - 1)%4 == 0:
		print("ccw")
	else:
		print("cw")
elif t in cwpos:
	if (n-1)%4 == 0:
		print("cw")
	else:
		print("ccw")
else:
	print("undefined")
