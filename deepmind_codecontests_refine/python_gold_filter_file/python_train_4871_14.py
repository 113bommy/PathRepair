x,y = map(int,input().split()) 
if x == 1 or y == 1:
  print(1)
else:
  print(-(-(x*y)//2))

