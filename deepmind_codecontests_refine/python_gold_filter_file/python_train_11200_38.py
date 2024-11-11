n = int(input())
sum = 0

for i in range(n):
    a = input()
    b = a.lower()
    if b == 'tetrahedron':
        sum += 4
    elif b == 'cube':
        sum += 6
    elif b == 'octahedron':
        sum += 8
    elif b == 'dodecahedron':
        sum += 12
    elif b == 'icosahedron':
        sum += 20
print(sum)
