x=int(input())
s=100
i=0
while s<x:
  s+=s//100
  i+=1
print(i)