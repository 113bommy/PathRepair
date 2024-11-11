n = int(input())
f = 0
for i in range(n):
    a = input()
    if a == 'Tetrahedron':
        f += 4
    elif a == 'Cube':
        f += 6
    elif a == 'Octahedron':
        f += 8
    elif a == 'Dodecahedron':
        f += 12
    elif a == 'Icosahedron':
        f += 20
print(f)