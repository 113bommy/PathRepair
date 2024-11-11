n = int(input(""))
for i in range(n):
  x = input("")
  if len(x)>10:
    s = len(x) - 2
    print(x[0]+str(s)+x[-1])
  else:
    print(x)  