n,a,b=[int(x) for x in input().split()]

if (a+b)%2==0:
  print((b-a)//2)
else:
  print(min(a-1,n-b)+1+(b-a-1)//2)