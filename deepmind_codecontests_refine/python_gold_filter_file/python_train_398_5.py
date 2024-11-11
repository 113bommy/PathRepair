n = list(input())

if len(n) % 2 == 0:
	for i in range(len(n)//2):
		if n[i] =="b":
			if n[-(i+1)] != "d":
				print("No")
				exit()
		elif n[i] == "p":
			if n[-(i+1)] != "q":
				print("No")
				exit()
		elif n[i] == "d":
			if n[-(i+1)] != "b":
				print("No")
				exit()
		elif n[i] == "q":
			if n[-(i+1)] != "p":
				print("No")
				exit()
	print("Yes")
else:
	print("No")