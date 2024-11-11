x = input()

count = 0
for i in range(len(x)):
	if x[i] == "H" or x[i] == "Q" or x[i] == "9":
		count += 1
	
		
if count > 0:
	print("YES")
else:
	print("NO")
	

