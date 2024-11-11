t=int(input())
while t!=0:
  a,b = input().split()
  a=int(a)
  b=int(b)
  if b>a:
    if (b-a)%2 == 0:
      print("2")
    elif b==a:
      print("0")
    else:
      print("1")
  else:
    if (b-a)%2 != 0:
      print("2")
    elif b==a:
      print("0")
    else:
      print("1")
  t = t-1