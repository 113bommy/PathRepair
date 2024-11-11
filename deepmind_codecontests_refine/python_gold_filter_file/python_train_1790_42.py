q = int(input())

for j in range(q):
  inp = int(input())
  if inp == 1:
    print("3")
  elif inp == 2:
    print("2")
  else:
    if inp % 2 == 0:
      print("0")
    else:
      print("1")