a,b=map(int,input().split(" "))
k=0
mensaje="YES"
L=[]
for i in range(b):
    c,d=map(int,input().split(" "))
    L.append([c,d])
L=sorted(L)
while(k<b):
    if(a>L[k][0]):
        a+=L[k][1]
    else:
        mensaje="NO"
        break
    k+=1
print(mensaje)