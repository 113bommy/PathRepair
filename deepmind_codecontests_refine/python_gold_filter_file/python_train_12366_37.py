x,*s=open(0)
h,w,k,*m=map(int,x.split())
for b in range(512):
 r=t=j=0;d=[0]*h
 while j<w:
  i=c=0
  while h-i:
   d[c]+=s[i][j]>'0';x=d[c]>k
   if(t<j)&x:r+=1;t=j;d=[0]*h;break
   r+=x*h*w;c+=b>>i&1;i+=1
  else:j+=1
 while b:r+=b&1;b>>=1
 m+=r,
print(min(m))