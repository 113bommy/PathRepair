n,k=list(map(int,input().split()))
r=list(map(int,input().split()))
r=list(map(lambda x: (x[1],x[0]),enumerate(r)))
a=[0 for i in r]
argues=[[] for i in r]

for i in range(k):
  x,y=list(map(int,input().split()))
  argues[x-1].append(y-1)
  argues[y-1].append(x-1)
  if r[x-1][0]>r[y-1][0]:
    a[x-1]+=1
  elif r[x-1][0]<r[y-1][0]:
    a[y-1]+=1
r.sort()

res=[0 for i in r]
d={}
for i in range(n):
  answ=i-a[r[i][1]]
  if r[i][0] not in d.keys():
    d[r[i][0]]=1
  else:
    answ-=d[r[i][0]]
    d[r[i][0]]+=1
  res[r[i][1]] = max(0,answ)
  
for i in res:
  print(i,end=' ')
