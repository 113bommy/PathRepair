n,k=map(int,input().split())
a=[int(input()) for i in range(n)]

def segfunc(x,y):
  return max(x,y)

def init(init_val):
  for i in range(n):
    seg[i+num-1]=init_val[i]
  for i in range(num-2,-1,-1):
    seg[i]=segfunc(seg[2*i+1],seg[2*i+2])

def update(k,x):
  k+=num-1
  seg[k]=x
  while k:
    k=(k-1)//2
    seg[k]=segfunc(seg[k*2+1],seg[k*2+2])

def query(p,q):
  if q<=p:
    return ide_ele
  p+=num-1
  q+=num-2
  res=ide_ele
  while q-p>1:
    if p&1==0:
      res=segfunc(res,seg[p])
    if q&1==1:
      res=segfunc(res,seg[q])
      q-=1
    p=p//2
    q=(q-1)//2
  if p==q:
    res=segfunc(res,seg[p])
  else:
    res=segfunc(segfunc(res,seg[p]),seg[q])
  return res

ide_ele=0

num=3*10**5+1
seg=[ide_ele]*2*num

dp=[0]*(max(a)+1)
dp[a[0]]=1
update(a[0],1)
for i in range(1,n):
  dp[a[i]]=query(max(a[i]-k,0),min(a[i]+k+1,3*10**5+1))+1
  update(a[i],dp[a[i]])
print(max(dp))