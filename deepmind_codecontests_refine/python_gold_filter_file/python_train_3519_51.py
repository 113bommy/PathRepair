n,k,*v=map(int,open(0).read().split())
m=0
r=range
for i in r(n+1):
 for j in r(min(k,n)-i+1):
  t=sorted(v[:i]+v[-j:]*(j>0))[::-1];c=k-i-j
  while t and c*t[-1]<0:t.pop();c-=1
  m=max(m,sum(t))
print(m)