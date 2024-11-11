a,b,c=map(int,input().split())
if c<=b:
  print("delicious")
elif c<=a+b:
  print("safe")
else:
  print("dangerous")