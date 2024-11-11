num = int(input())
faces = 0

while num:
    polyhedron = input()
    if polyhedron == 'Tetrahedron':
        faces += 4
    elif polyhedron == 'Cube':
        faces += 6
    elif polyhedron == 'Octahedron':
        faces += 8
    elif polyhedron == 'Dodecahedron':
        faces += 12
    else:
        faces += 20
    num -= 1
    
print(faces)