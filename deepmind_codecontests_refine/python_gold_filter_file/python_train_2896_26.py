n,k=map(int,input().split())
a=list(map(int,input().split()))

l=[]
for i in range(n):
  s=0
  for j in range(i,n):
    s+=a[j]
    l.append(s)
t=0
for i in range(40,-1,-1):
  t+=2**i
  c=0
  for j in l:
    if t==j&t:
      c+=1
  if c<k:
    t-=2**i
print(t)