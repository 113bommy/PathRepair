n = int(input())
list = []
num = 0
for x in range(n):
	list.append(input())

for i in list:
	if i == "Tetrahedron":
		num = num + 4
	elif i == "Cube":
		num = num + 6
	elif i == "Octahedron":
		num = num + 8
	elif i == "Dodecahedron":
		num = num + 12
	elif i == "Icosahedron":
		num = num + 20
print(num)

