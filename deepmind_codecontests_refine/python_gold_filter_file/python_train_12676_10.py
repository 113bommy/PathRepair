l,r,x,y=map(int,input().split())
h=()
a=0
if y%x<1:
 s=y=y//x
 for i in range(2,int(y**.5)+1):
  j=1
  while y%i<1:
   j*=i;y//=i
  if j>1:h+=j,
 if y>1:h+=y,
 for i in range(1<<len(h)):
  p=1
  for j,u in enumerate(h):
   if(i>>j)&1:p*=u
  a+=l<=p*x<=r and l<=s//p*x<=r
print(a)