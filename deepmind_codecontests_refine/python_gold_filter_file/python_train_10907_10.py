x,k,d=map(int,input().split())
x=abs(x)
if k*d<=x:
  print(x-d*k)
elif (k-x//d)%2==0:
  print(x%d)
else:
  print(d-x%d)