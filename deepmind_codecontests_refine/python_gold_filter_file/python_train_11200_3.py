n=int(input())
count=0
while(n):
    s=input()
    if s=="Tetrahedron":
        count=count+4
    elif s=="Cube":
        count=count+6
    elif s=="Octahedron":
        count=count+8
    elif s=="Dodecahedron":
        count=count+12
    else:
        count=count+20
    n=n-1
print(count)