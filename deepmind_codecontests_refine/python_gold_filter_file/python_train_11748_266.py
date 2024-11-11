X,A,B=map(int,input().split())
if B<=A:
  print("delicious")
elif X>=B-A:
  print("safe")
else:
  print("dangerous")