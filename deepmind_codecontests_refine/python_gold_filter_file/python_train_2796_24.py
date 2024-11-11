n,x=list(map(int,input().split()))
if x==1 or x==2*n-1:
  print("No")
elif x==2*n-2:
  print("Yes")
  for i in range(n-1):
    print(i+1)
  print(x)
  print(2*n-1)
  for i in range(n-1,x-1):
    print(i+1)
else:
  print("Yes")
  l=[i for i in range(1,x-1)]+[i for i in range(x,2*n-3)]
  for i in range(n-2):
    print(l[i]+1)
  print(2*n-1)
  print(x)
  print(1)
  print(2*n-2)
  for i in range(n-2,2*n-5):
    print(l[i]+1)