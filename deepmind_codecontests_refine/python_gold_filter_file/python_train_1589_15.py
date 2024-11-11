t= int(input())
for i in range(t):
  x,y,n= map(int,input().split())
  if n%x>=y:
    print((n//x)*x+y)
  else:
    print((n//x-1)*x+y)