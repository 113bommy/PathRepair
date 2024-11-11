import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
n=int(input())
m=[]
for i in range(n):
  a=list(map(int,input().split()))
  a.reverse()
  m.append(a)
ans=0
count=0
failflag=0
previous=set()
for i in range(n):
  previous.add(i)
while count<(n*(n-1)):
  ans+=1
  tempcount=count
  r=set()
  for i in previous:
    if m[i]:
      t=m[i][-1]
      if m[t-1]:
        if m[t-1][-1]==i+1:
          count+=1
          r.add(i)
          r.add(t-1)
  previous=set()
  for k in r:
    m[k].pop()
    previous.add(k)
    if m[k]:
      previous.add(m[k][-1]-1)
  if tempcount==count:
    failflag=1
    break
if failflag==1:
  print(-1)
else:
  print(ans)
    
