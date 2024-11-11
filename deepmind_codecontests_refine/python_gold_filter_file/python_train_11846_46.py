x=int(input())
t=0
y=100
while y<x:
  y+=y//100
  t+=1
print(t)