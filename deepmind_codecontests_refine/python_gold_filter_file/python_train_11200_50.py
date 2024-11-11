num = int(input())
total = 0
for i in range (0,num):
    a = str(input())
    if (a == "Tetrahedron"):
        total += 4
    elif (a == "Cube"):
        total += 6
    elif (a == "Octahedron"):
        total += 8
    elif (a == "Dodecahedron"):
        total += 12
    elif (a == "Icosahedron"):
        total += 20
    else:
        print("SHAPE NOT FOUND!")
print (total)
