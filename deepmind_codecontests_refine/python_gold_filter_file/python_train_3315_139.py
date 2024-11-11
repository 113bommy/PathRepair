a,s=map(int,input().split())
if a%3==0 or s%3==0 or (a+s)%3==0:
  print("Possible")
else:
  print("Impossible")