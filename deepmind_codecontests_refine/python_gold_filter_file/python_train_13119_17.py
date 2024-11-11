while True:
  x=input()
  if x == '0':
   break
  print(sum(int(z) for z in x))