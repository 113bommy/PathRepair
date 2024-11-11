a = int(input())
home_clothes = []
front_clothes = []
for i in range(a):
	b = input()
	b = b.split()
	home_clothes.append(b[0])
	front_clothes.append(b[1])
summa = 0
for i in home_clothes:
	for u in front_clothes:
		if i == u:
			summa += 1
print(summa)