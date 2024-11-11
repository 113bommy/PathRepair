X,N=map(int,input().split())
if N==0:
  print(X)
else:
  p=set(map(int,input().split()))
  i=-1
  for j in range(102):
    if abs(X-j)<abs(X-i) and not(j in p):
      i=j
  print(i)