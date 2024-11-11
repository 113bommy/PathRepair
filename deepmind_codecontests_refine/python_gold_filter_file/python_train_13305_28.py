a,b = [int(k) for k in input().split()]
if b%a:
  print(abs(b-a))
else:
  print(a+b)