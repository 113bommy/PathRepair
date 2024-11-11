n=int(input())
q=0
for i in range(n):
    s=input()
    q+=4*(s=='Tetrahedron')+6*(s=='Cube')+8*(s=='Octahedron')+12*(s=='Dodecahedron')+20*(s=='Icosahedron')
print(q)