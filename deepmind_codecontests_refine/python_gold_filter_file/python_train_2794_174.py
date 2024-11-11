a,x,y = map(int,input().split())

if abs(a-x) < abs(a-y):
  print('A')
else:
  print('B')