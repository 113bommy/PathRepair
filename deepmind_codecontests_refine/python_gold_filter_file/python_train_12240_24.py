import math
ent=input()
n,m,k=ent.split()
saida=list()
saida.append(math.ceil(float(k)/(2*float(m))))
if math.ceil((int(k)%(2*int(m)))/2)!=0:
  saida.append(math.ceil((int(k)%(2*int(m)))/2))
else:
  saida.append(int(m))

if int(k)%2==0:
  saida.append('R')
else:
  saida.append('L')
  
print("{} {} {}".format(saida[0],saida[1],saida[2]))