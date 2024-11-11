a,a1,a2=input().split()
b=int(a)

if a2=='week':
	if 7>b>4:
		print(53)
	else:
		print(52)
else:
	if b==31:
		print(7)
	elif b==30:
		print(11)
	else:
		print(12)
