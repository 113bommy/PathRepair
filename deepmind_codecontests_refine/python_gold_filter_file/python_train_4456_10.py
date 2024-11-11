n=int(input())
a=[]
d=[]
for i in range(n):
  c=[]
  b=int(input())
  d.append(b)
  for j in range(b):
    c.append(list(map(int,input().split())))
  a.append(c)


count=0
for i in range(2**n):
  x=[0]*n
  pre=0
  for j in range(n):
    if ((i>>j)&1):
      x[n-1-j]=1 
      for l in range(d[j]):
        if ((i>>(a[j][l][0]-1))&1)!=a[j][l][1]:
          pre+=1
  if pre!=0:
    count=count
  else:
    count=max(count,x.count(1))
print(count)