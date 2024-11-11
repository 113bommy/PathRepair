LT=input()
L=input()
LT=LT.split(" ")
L=L.split(" ")
Tama=L
Tama.append(0)
Tama.append(LT[1])
T=[]
for i in range(0,len(Tama)):
    T.append(int(Tama[i]))
Tama=T
Tama=sorted(Tama)
D=[]
for i in range(0,len(Tama)-1):
    if(i==0 or i==len(Tama)-2):
       D.append(Tama[i+1]-Tama[i])
    else:
       D.append((Tama[i+1]-Tama[i])/2)
D=sorted(D)
print(D.pop())
