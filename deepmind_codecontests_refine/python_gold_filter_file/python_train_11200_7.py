n=int(input())
k=0
for i in range(n):
	s=input()
	if s=='Icosahedron':
		k+=20
	elif s=='Dodecahedron':
		k+=12
	elif s=='Octahedron':
		k+=8
	elif s=='Cube':
		k+=6
	else:
		k+=4
print(k)