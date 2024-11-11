n=int(input())
a=n//100
b=n%100
if 0<=b<=5*a:
  print(1)
else:
  print(0)