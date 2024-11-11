n = int(input())
count = 0
for i in range(n):
    a = input()
    if a=="Icosahedron":
        count += 20
    elif a == "Dodecahedron":
        count += 12
    elif a == "Octahedron":
        count += 8
    elif a == "Cube":
        count += 6
    elif a == "Tetrahedron":
        count +=4
print(count)