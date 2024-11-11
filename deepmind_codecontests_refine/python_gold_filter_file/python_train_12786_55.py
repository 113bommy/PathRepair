n = int(input())

for i in range(n//7+1):
	if n%4==0:
		print("Yes")
		break
	n -=7
else:
	print("No")
