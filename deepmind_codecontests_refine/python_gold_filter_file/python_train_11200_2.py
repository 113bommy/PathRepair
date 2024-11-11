i=int(input())
l=[input() for o in range(i)]
faces=0
for x in range(i):
    if l[x]==("Tetrahedron"):
        faces=faces+4
    elif l[x]==("Cube"):
        faces=faces+6
    elif l[x]==("Octahedron"):
        faces=faces+8
    elif l[x]==("Dodecahedron"):
        faces=faces+12
    elif l[x]==("Icosahedron"):
        faces=faces+20
print(faces)
