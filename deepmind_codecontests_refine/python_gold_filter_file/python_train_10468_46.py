n=input()
if n[0]=='h' or n[0]=='a':
	if n[1]=='1' or n[1]=='8':
		print(3)
	else:
		print(5)
elif n[1]=='1' or n[1]=='8':
	if n[0]=='a' or n[0]=='h':
		print(3)
	else:
		print(5)
else:
	print(8)