n1=int(input())
s=0
for i in range(n1):
     n=input()
     
     if(n=="Tetrahedron"):
          s+=4
     elif(n=="Cube"):
          s+=6
     elif(n=="Octahedron"):
          s+=8
     elif(n=="Dodecahedron"):
          s+=12    
     elif(n=="Icosahedron"):
          s+=20
print(s)          