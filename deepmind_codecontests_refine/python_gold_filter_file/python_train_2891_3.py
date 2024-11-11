class UnionFind():
  def __init__(self,n):
    self.n=n
    self.root=[-1]*(n+1)
    self.rank=[0]*(n+1)
  def FindRoot(self,x):
    if self.root[x]<0:
      return x
    else:
      self.root[x]=self.FindRoot(self.root[x])
      return self.root[x]
  def Unite(self,x,y):
    x=self.FindRoot(x)
    y=self.FindRoot(y)
    if x==y:
      return
    else:
      if self.rank[x]>self.rank[y]:
        self.root[x]+=self.root[y]
        self.root[y]=x
      elif self.rank[x]<=self.rank[y]:
        self.root[y]+=self.root[x]
        self.root[x]=y
        if self.rank[x]==self.rank[y]:
          self.rank[y]+=1
  def isSameGroup(self,x,y):
    return self.FindRoot(x)==self.FindRoot(y)
  def Count(self,x):
    return -self.root[self.FindRoot(x)]
  
n=int(input())
uf=UnionFind(n)
arr=[list(map(int,input().split()))+[i+1] for i in range(n)]
arr=sorted(arr,key=lambda x:x[0])
x,y,i=arr[0]
tmp=[]
for tx,ty,j in arr:
  if y<=ty:
    uf.Unite(i,j)
    for tx2,ty2,j2 in tmp:
      if ty2<=ty:
        uf.Unite(j,j2)
    tmp=[]
  else:
    tmp.append([x,y,i])
    x=tx
    y=ty
    i=j
arr=sorted(arr,reverse=True,key=lambda x:x[1])
x,y,i=arr[0]
tmp=[]
for tx,ty,j in arr:
  if x>=tx:
    uf.Unite(i,j)
    for tx2,ty2,j2 in tmp:
      if tx2>=tx:
        uf.Unite(j,j2)
    tmp=[]
  else:
    tmp.append([x,y,i])
    x=tx
    y=ty
    i=j
for i in range(1,n+1):
  print(uf.Count(i))