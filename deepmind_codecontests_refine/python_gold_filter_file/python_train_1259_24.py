def overenie(pocPismen, pismena):
	for j in range(int(pocPismen/2)):
		x = abs(ord(pismena[j]) - ord(pismena[-(j+1)]))
		if x == 2 or x == 0:
			pass
		else:
			return("NO")
	
	return("YES")


pocSlov = int(input())
odpovede = []
for i in range(pocSlov):
	pocPismen = int(input())
	pismena = input()
	
	odpovede.append(overenie(pocPismen, pismena))
	
for i in odpovede:
	print(i)
	