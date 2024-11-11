a,b = (int(j) for j in input().split())
if b%a == 0:
  print(a+b)
else:
  print(b-a)