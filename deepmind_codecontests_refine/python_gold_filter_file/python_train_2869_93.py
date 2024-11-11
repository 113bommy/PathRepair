cycle = int(input())
for num in range(0,cycle):
  inp = input()
  lenth = int(len(inp))
  if lenth<=10:
    print(inp)
  else:
    print(inp[0:1]+str(lenth-2)+inp[lenth-1:lenth])