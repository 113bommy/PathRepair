a=int(input())
s=0
for i in range(0,a):
    b=input()
    if(b=="Tetrahedron"):
        s=s+4
    elif(b=="Cube"):
        s=s+6
    elif(b=="Octahedron"):
        s=s+8
    elif(b=="Dodecahedron"):
        s=s+12
    elif(b=="Icosahedron"):
        s=s+20
print(s)
        
