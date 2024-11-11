for t in range(int(input())):
	
	n = int(input())	
	string = "3 1 4 2"

	if n>3:
		for i in range(5,n+1):
			if i&1:
				string += " "+str(i)
			else:
				string = str(i)+" " + string
		print(string)
	else:
		print(-1)
