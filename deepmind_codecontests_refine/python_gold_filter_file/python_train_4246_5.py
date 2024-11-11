N, M = map(int, input().split())

par = list(range(N))
rank = [1]*N
size = [1]*N

def find(x):
  if par[x] == x:
    return x
  else:
    return find(par[x])
  
def unite(x,y):
  x = find(x)
  y = find(y)
  
  if x == y:
    return
  if rank[x]<rank[y]:
    x,y = y,x
  par[y] = x
  size[x] += size[y]
  if rank[x]==rank[y]:
    rank[x]+=1
    
for i in range(M):
  a,b = [int(i)-1 for i in input().split()]
  unite(a,b)
  
print(max(size))