x,y=map(int,input().split())
r=4*x
if r>=y and y>=2*x and (r-y)%2==0:
  print('Yes')
else:
  print('No')
