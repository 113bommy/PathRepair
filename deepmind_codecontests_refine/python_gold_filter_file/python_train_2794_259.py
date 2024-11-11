x, a, b = map(int, input().split())
if abs(b-x)<abs(a-x):
  print('B')
else:
  print('A')