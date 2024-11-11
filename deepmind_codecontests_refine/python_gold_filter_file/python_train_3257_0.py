R=lambda:map(int,input().split())
t,=R()
for _ in[0]*t:
 n,w=R();r=[];i=s=0
 for x in R():
  i+=1
  if 2*x<w:r+=i,;s+=x
  elif x<=w:print(1,i);break
  if 2*s>=w:print(len(r),*r);break
 else:print(-1)