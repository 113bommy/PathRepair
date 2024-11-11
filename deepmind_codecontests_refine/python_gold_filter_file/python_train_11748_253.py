x,a,b=map(int,input().split())
if b<=a:
  print("delicious")
elif x+a>=b:
  print("safe")
else:
  print("dangerous")