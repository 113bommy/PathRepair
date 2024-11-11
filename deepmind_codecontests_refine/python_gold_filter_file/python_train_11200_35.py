n = int(input())
output = 0
t = 'Tetrahedron'
c = 'Cube'
o = 'Octahedron'
d = 'Dodecahedron'
i = 'Icosahedron'
for x in range(n):
	geom = str(input())
	if geom == t:
		output+= 4
	if geom == c:
		output+= 6
	if geom == o:
		output+= 8
	if geom == d:
		output+= 12
	if geom == i:
		output+= 20
print(output)


