x,a,b = map(int,input().split())
if 0<=a-b:
  print('delicious')
elif b-a<x+1:
  print('safe')
else:
  print('dangerous')