n = input()
n = n.split()
m = int(n[1])
n = int(n[0])

c=0
for i in range(1,n+1):
	if i%2!=0:
		for j in range(m):
			print("#",end = "")
		print()
	else:
		c+=1
		if c%2!=0:
			for j in range(m-1):
				print(".",end = "")
			print("#")
		else:
			print("#",end = "")
			for j in range(m-1):
				print(".",end = "")
			print()
	