e=input().split()
p=int(e[0])
a=int(e[1])
b=int(e[2])
negativo= b<0
b=abs(b)
i=a
if(negativo):
  while b>0:
    if i == 0:
      i=p
    i-=1
    b-=1  
else:
  while b>0:
    if i == p:
      i=0
    i+=1
    b-=1  
if i!=0:
  print(i)
else:
  print(p)