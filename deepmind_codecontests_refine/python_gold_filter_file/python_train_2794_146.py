x,y,z = map(int,input().split())
if abs(x-y) > abs(x-z):
  print('B')
else:
  print('A')