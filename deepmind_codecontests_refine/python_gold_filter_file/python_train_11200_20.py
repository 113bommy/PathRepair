# "Tetrahedron" (without quotes), if the i-th polyhedron in Anton's collection is a tetrahedron.
# "Cube" (without quotes), if the i-th polyhedron in Anton's collection is a cube.
# "Octahedron" (without quotes), if the i-th polyhedron in Anton's collection is an octahedron.
# "Dodecahedron" (without quotes), if the i-th polyhedron in Anton's collection is a dodecahedron.
# "Icosahedron" (without quotes), if the i-th polyhedron in Anton's collection is an icosahedron.
n=int(input())
c=0
for i in range(n):
    a=input()
    if(a=="Tetrahedron"):
        c=c+4
    elif(a=="Cube"):
        c=c+6
    elif(a=="Dodecahedron"):
        c=c+12
    elif(a=="Octahedron"):
        c=c+8
    elif(a=="Icosahedron"):
        c=c+20
print(c)