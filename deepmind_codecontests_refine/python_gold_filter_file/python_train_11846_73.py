x=int(input())
p=100
c=0
while p<x:
  p=p+int(p/100)
  c+=1
print(c)