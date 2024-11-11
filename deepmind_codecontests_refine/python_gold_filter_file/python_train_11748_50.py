a,b,c=map(int,input().split())
if c-b>a:
  print("dangerous")
elif c>b:
  print("safe")
else:
  print("delicious")