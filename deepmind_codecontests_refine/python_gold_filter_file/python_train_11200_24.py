n=int(input())
f=0
for i in range(n):
    x=input()
    if x=='Tetrahedron':  
        f=4+f
    elif x=='Cube':
        f=6+f
    elif x=='Octahedron':
        f=8+f
    elif x=='Dodecahedron':
        f=12+f
    elif x=='Icosahedron':
        f=20+f
print(f)    
    