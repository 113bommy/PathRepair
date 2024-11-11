r=range
h,*s=open(0)
h,w,k=map(int,h.split())
m=9e9
for i in r(1<<h-1):
 t,v,l=[],-1,1
 for j in r(h):z=i>>j&1;t+=[j+1]*z;l+=z
 t+=h,
 c=[0]*l
 for i in r(w):
  b=f=g=0;u=[]
  for j in r(l):d,b=sum(s[j][i]>"0"for j in r(b,t[j])),t[j];u+=d,;g|=d>k;c[j]+=d;f|=c[j]>k
  v+=f
  if f:c=u
 if g<1:m=min(m,v+l)
print(m)