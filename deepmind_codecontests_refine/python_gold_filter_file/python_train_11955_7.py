from collections import*
from heapq import*
(n,m),a,*q=[[*map(int,o.split())]for o in open(0)]
t=[-1]*n
def r(x):
 while t[x]>=0:x=t[x]
 return x
def u(x,y):
 x,y=r(x),r(y)
 if x!=y:
  if t[x]>t[y]:x,y=y,x
  t[x]+=t[y];t[y]=x
d=defaultdict(list)
for x,y in q:u(x,y)
i=c=0;b=[];k=(n+~m)*2
for v in a:d[r(i)]+=v,;i+=1
if k<1:exit(print(0))
for r,p in d.items():p.sort();c+=p.pop(0);b+=p;k-=1
print(k>len(b)and'Impossible'or c+sum(sorted(b)[:k]))