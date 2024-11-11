n,x,y=map(int,input().split())
l=list(input())
if(l[0]=='0'):
  c=1
else:
  c=0
for i in range(1,n):
  if(l[i]=='0' and l[i-1]=='1'):
    c=c+1
if(c==0):
  print(0)
elif(x>y):
  print(c*y)
else:
  print((c-1)*x+y)


