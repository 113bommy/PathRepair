x,y=map(int,input().split())
ans="No"
if (y-2*x)%2==0 and 0<=(y-2*x)/2<=x:
  ans="Yes"
print(ans)