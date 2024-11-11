X,A,B=map(int,input().split())
if B-A<=0 :
  print("delicious")
elif B-A<X+1 :
  print("safe")
else :
  print("dangerous")