x,a,b=map(int,input().split())

if b<=a:
  print("delicious")
elif b>a+x:
  print("dangerous")
else:
  print("safe")