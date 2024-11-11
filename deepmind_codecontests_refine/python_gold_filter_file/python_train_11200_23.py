n = int(input())
slova = {'Cube': 6, 'Tetrahedron': 4, 'Dodecahedron': 12, 'Icosahedron': 20, 'Octahedron': 8}
tot = 0
for i in range(n):
	tot += slova[input()]
print(tot)