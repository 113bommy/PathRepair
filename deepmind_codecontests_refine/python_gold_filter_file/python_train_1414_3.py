x, y, z= map(int, input().split())


if x>0 and x<=10**9 and y>=0 and y<=10**9 and z>=0 and z<=10**9 and y+z>0:
  if x>y and x>z:
    print(-1)
  elif y>x and y%x!=0 and x>z:
    print(-1)
  elif x>y and z%x!=0 and z>x:
    print(-1)
  else:
    print((y//x)+(z//x))
else:
  print(-1)