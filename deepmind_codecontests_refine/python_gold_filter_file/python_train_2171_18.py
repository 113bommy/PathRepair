a,b,c=map(int,input().split())
if a==b==c:
  print(-1 if a%2==0 else 0)
else:
  x=0
  while ((a-1)*(b-1)*(c-1))%2==1:
    a,b,c=(b+c)//2,(a+c)//2,(a+b)//2
    x+=1
  print(x)