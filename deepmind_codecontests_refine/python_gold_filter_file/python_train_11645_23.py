N,A,B=map(int,input().split())
if A>B:
  print(0)
elif N==1 and A!=B:
  print(0)
else:
  print((N-2)*(B-A)+1)