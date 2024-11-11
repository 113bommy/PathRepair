k,a,b=map(int,input().split())
ans=0
k-=a
if k<=0:
  print(1)
elif a-b<=0:
  print(-1)
else:
  print(2*((k-1)//(a-b)+1)+1)
