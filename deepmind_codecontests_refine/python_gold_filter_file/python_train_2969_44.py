x = input().split()
if x[2] == "week":
	if x[0] == "5" or x[0] == "6":
		print("53")
	else:
		print("52")
else:
	if x[0] == "31":
		print(7)
	elif x[0] == "30":
		print(11)
	else:
		print(12)