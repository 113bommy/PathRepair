N=input()
s=list(input())
r=s.count("R")
b=s.count("B")
if r>b:
  print("Yes")
else:
  print("No")