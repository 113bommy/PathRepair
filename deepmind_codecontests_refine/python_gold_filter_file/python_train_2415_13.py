n = int(input())
nn = n
i = 2
dziel = []
while True:
	if n%i == 0:
		n //= i
		dziel.append(i)
	else:
		i += 1
	if i**2 > nn:
		if n > 1:
			dziel.append(n)
		break
if len(dziel) == 1:
	print(nn)
else:
	a = set(dziel)
	if len(a) == 1:
		print(dziel[0])
	else:
		print(1)