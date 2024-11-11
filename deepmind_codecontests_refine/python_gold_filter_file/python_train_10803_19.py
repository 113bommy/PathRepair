n=int(input())
d={}
for k in range(2,10**6):
  while n%k<1: n//=k; d[k]=d.get(k,0)+1
a=0
for i in d.values():
  t=c=0
  while t+c<i: c+=1; t+=c
  a+=c
print(a+(n>1))