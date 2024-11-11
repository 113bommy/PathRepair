r=lambda x:x if u[x]<0else r(u[x])
n,m,*e=map(int,open(0).read().split())
u=[-1]*-~n
t=n*~-n//2
a=[t]
for x,y in zip(e[-2:1:-2],e[:1:-2]):
 x,y=sorted((r(x),r(y)))
 if x!=y:t-=u[x]*u[y];u[x]+=u[y];u[y]=x
 a+=t,
print(*a[::-1],sep='\n')