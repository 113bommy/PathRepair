n=int(input())
sum1=0
for _ in range(n):
    s=input()
    if(s=="Tetrahedron"):
        sum1+=4
    elif(s=="Cube"):
        sum1+=6
    elif(s=="Octahedron"):
        sum1+=8
    elif(s=="Dodecahedron"):
        sum1+=12
    else:
        sum1+=20
print(sum1)

    
        
        