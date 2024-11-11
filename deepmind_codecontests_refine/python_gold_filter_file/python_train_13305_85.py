a,b = map(int, input().split())
if (b//a) * a == b:
  print(a+b)
else:
  print(b-a)