X,Y=map(int,input().split())
if X%3==0 or Y%3==0 or (X+Y)%3==0:
  print("Possible") 
else:
  print("Impossible")