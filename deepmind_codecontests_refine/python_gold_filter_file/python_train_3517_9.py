def find(x):
    if par[x]<0:
        return x
    else:
        par[x]=find(par[x])
        return par[x]

def unite(x,y):
  x,y=find(x),find(y)
  if x!=y:
    if x>y:
        x,y=y,x
    par[x]+=par[y]
    par[y]=x
    
def same(x,y):
  return find(x)==find(y)

def size(x):
  return-par[find(x)]
  
n,m,k=map(int,input().split())

par=[-1]*n

F=[]
B=[]

f=[set() for _ in range(n)]

for i in range(m):
    a,b=map(int,input().split())
    F.append([a,b])
    
for i in range(k):
    c,d=map(int,input().split())
    B.append([c,d])

for a,b in F:
    a-=1
    b-=1
    unite(a,b)
    f[a].add(b)
    f[b].add(a)

a=[size(i)-len(f[i])-1 for i in range(n)]

for c,d in B:
    c-=1
    d-=1
    if same(c,d):
        a[c]-=1
        a[d]-=1
print(*a)
