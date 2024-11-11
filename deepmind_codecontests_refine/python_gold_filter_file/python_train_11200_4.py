n = int(input())
s = 0
for i in range(n):
    t = input()
    if t == 'Tetrahedron':
        s += 4
    elif t == 'Cube':
        s += 6
    elif t == 'Octahedron':
        s += 8
    elif t == 'Dodecahedron':
        s += 12
    elif t == 'Icosahedron':
        s += 20
print(s)