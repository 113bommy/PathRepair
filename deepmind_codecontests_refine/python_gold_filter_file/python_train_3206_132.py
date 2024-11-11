a,b,k=map(int,input().split())
if a >= k:
  print(a-k,b)
else:
  print(0,max(a-k+b,0))