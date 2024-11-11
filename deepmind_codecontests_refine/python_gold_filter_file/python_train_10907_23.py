x,k,d=map(int,input().split())

x=abs(x)

if x>=k*d:
  print(x-(k*d))
else:
  nk=k-x//d
  x%=d
  if nk%2:
    print(abs(x-d))
  else:
    print(x)