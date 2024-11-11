s=0
l=[]
n=int(input())
for i in range(n):
    e = input()
    l.append(e)
for i in l:
    if (i == "Tetrahedron"):
        s+=4
    elif (i == "Cube"):
        s+=6
    elif (i == "Octahedron"):
        s+=8
    elif (i == "Dodecahedron"):
        s+=12
    elif (i == "Icosahedron"):
        s+=20
print(s)