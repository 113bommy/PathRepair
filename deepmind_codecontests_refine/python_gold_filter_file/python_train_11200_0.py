n =int(input())
c=0
for i in range(n):
	s=input()
	if s=="Cube":
	    c=c+6
	elif s=="Tetrahedron":
	    c=c+4
	elif s=="Icosahedron":
	    c=c+20
	elif s=="Dodecahedron":
	    c=c+12
	elif s=="Octahedron":
	    c=c+8
print(c)