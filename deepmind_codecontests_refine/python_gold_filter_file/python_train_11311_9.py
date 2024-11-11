a,b = [int(i) for i in input().split()]
while a and b:
  if a >=2*b:
    a = a%(2*b)
  elif b >= 2*a:
    b = b%(2*a) 
  else:
    break

print(a,b)