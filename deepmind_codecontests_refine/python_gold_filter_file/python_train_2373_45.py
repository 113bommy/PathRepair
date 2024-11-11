N=int(input())
r=N%100
d=int((N-r)/100)
 
if r>5*d:
  print(0)
else:
  print(1)
