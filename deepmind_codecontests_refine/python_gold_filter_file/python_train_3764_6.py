a=input()
b=[]
b=a.split(" ")
z=0
while(len(b)>z):
  b[z]=int(b[z])
  z=z+1
b.sort()
d=int(b[3])-int(b[2])
e=int(b[3])-int(b[1])
f=int(b[3])-int(b[0])
print(d, end=" ")
print(e, end=" ")
print(f)
