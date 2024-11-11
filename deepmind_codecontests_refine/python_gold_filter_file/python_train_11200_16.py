

num = int(input())
sum = 0
values = {"Tetrahedron":4,"Cube":6,"Octahedron":8,"Dodecahedron":12,"Icosahedron":20}

for i in range(0, num):
	sum += values[input()]

print(sum)
