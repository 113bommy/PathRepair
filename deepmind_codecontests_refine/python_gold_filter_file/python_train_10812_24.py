s,k=open(0)
k=int(k)
*l,=map(ord,s[:-1])
for i,t in enumerate(l):
  j=(19-t)%26
  if j<=k:k-=j;l[i]=97
l[-1]+=k%26
print(*map(chr,l),sep='')