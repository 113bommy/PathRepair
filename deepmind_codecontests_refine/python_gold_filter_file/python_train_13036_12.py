t = int(input())
for i in range(t):
  a,b,c = map(int,input().split())
  if a>=4 and b>=4 and c>=4:
    print(7)
  else:
    x = [a,b,c]
    x.sort()
    if x[0] == 3:
      print(6)
    elif x[0] == 2:
      if sum(x) >= 7:
        print(5)
      else:
        print(4)
    elif x[0] == 1:
      if x[1] >= 2:
        print(4)
      else:
        print(3)
    elif x[0] == 0:
      if x[1] >= 2:
        print(3)
      elif x[1] == 1:
        print(2)
      else:
        print(min(x[2],1))