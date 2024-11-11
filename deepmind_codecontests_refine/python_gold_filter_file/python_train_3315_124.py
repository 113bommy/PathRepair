x,y=map(int, input().split())
if x%3!=0 and y%3!=0 and (x+y)%3!=0:
  print('Impossible')
else:
  print('Possible')