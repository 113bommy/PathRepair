t=int(input())
d=t//2
print(d)
if t%2==1:
  d-=1;
  for i in range(d):
    print(2,end=" ")
  print(3)
else:
  for i in range(1,d):
    print(2,end=" ")
  print(2)