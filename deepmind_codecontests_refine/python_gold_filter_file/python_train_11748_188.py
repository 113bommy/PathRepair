a,s,d=map(int,input().split())
if s-d>=0:
  print("delicious")
elif a+s-d>=0:
  print("safe")
else:
  print("dangerous")
