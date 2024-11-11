N=int(input())

a={}
c=0
while N%2==0:
  N//=2
  c+=1
if c!=0:
  a[2]=c

f,c=3,0
while f*f<=N:
  if N%f==0:
    N//=f
    c+=1
    a[f]=c
  else:
    f+=2
    c=0
if N!=1:
  if N in a:
    a[N]+=1
  else:
    a[N]=1

t=0
for v in a.values():
  i=1
  while v>=i:
    t+=1
    v-=i
    i+=1

print(t)
