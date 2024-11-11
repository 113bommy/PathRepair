for _ in [0]*int(input()):
 s=list(input())
 a='0Aa'
 l=[[],[],[]]
 for i,c in enumerate(s):
  l[(c>'9')+(c>'Z')]+=[i]
 i=j=k=-1
 for m,x in enumerate(l):
  if not x:i=m
  else:
   j=m
   if len(x)>1:k=m
 n=sum(bool(x)for x in l)
 if n==1:
  s[:2]=a[(j+1)%3],a[(j+2)%3]
 if n==2:
  s[l[k][0]]=a[i]
 print(''.join(s))
