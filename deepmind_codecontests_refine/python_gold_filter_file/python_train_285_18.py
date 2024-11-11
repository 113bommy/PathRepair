from heapq import*
i=input
for s in[0]*int(i()):
 n,x,*y=int(i()),[]
 for _ in'_'*n:k,l,r=t=[*map(int,i().split())];x+=[t]*(l>r);y+=[[n-k,r,l]]*(l<=r)
 for x in x,y:
  x.sort();n=len(x);h=[(0,0)]*n*2
  while h:
   while[[n]]<x[-1:]:k,l,r=x.pop();heappush(h,(r-l,l,r))
   s+=heappop(h)[~(n>0)];n-=1
 print(s)