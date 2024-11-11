n,k,*v=map(int,open(0).read().split())
m=0
for i in range(n):
 for j in range(min(k,n)-i+1):
  t=sorted(v[:i]+v[:~j:-1])
  while t and(k-i-j)*t[0]<0:t.pop(0);j+=1
  m=max(m,sum(t))
print(m)