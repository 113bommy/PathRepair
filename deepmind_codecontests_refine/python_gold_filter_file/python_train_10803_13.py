n=int(input())
d={2:0}
while n%2<1:  n//=2;  d[2]+=1
for i in range(3,int(n**0.5)+1,2):
  while n%i<1:  n//=i;  d[i]=d.get(i,0)+1
  if n<2: break
if n>1: d[n]=1
a=0
for i in d.values():
  t=c=0
  while t+c<i: c+=1; t+=c
  a+=c
print(a)