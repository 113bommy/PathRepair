X,Y,Z = map(int,input().split())
if abs(Y-X) > abs(Z-X):
  print('B')
else:
  print('A')