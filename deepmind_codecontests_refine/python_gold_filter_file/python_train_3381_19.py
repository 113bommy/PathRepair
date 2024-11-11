a,b,s=list(map(int,input().split()))
y=s-(abs(a)+abs(b))
if(y%2==0 and y>=0):
  print("Yes")
else:
  print("No")
