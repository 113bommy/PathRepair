x,n=map(int,input().split())
if n==0:
  print(x)
else:
  a=list(map(int,input().split()))
  ans=-1
  for i in range(0,102):
    if i not in a and abs(i-x)<abs(ans-x):
      ans=i
  print(ans)
