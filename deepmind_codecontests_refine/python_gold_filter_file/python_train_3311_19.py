a,b,c,n=map(int,input().split())
ans=0
for x in range((n+a)//a):
  for y in range((n+b-a*x)//b):
    z=n-a*x-b*y
    if z>=0 and z%c==0:
      ans+=1
print(ans)
