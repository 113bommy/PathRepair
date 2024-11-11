n=int(input())

a=[]
for i in range(n):
        t=input()
        a.append(t)
sum=0
for i in a:
        if i=="Tetrahedron":
                sum+=4
        elif i=="Cube":
                sum+=6
        elif i=="Octahedron":
                sum+=8
        elif i=="Dodecahedron":
                sum+=12
        else:
                sum+=20
        
print(sum)
