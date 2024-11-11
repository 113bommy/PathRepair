class UnionFind:
  def __init__(self, n):
    self.par = [i for i in range(n)]
    self.rank = [0]*n
  def find(self, x):
    if self.par[x]==x:
      return x
    else:
      self.par[x] = self.find(self.par[x])
      return self.par[x]
  def unit(self, x, y):
    x = self.find(x)
    y = self.find(y)
    if x==y:
      return
    elif self.rank[x]<self.rank[y]:
      self.par[x] = y
    elif self.rank[y]<self.rank[x]:
      self.par[y] = x
    else:
      self.par[y] = x
      self.rank[x] += 1
      
  def same(self, x, y):
    return self.find(x)==self.find(y)

from collections import defaultdict
N,M,*L = map(int, open(0).read().split())
A = L[:N]
U = UnionFind(N)
for x,y in zip(*[iter(L[N:])]*2):
  U.unit(x,y)
ans = 0
rest = []
dic = defaultdict(list)
for i in range(N):
  dic[U.find(i)].append(A[i])
for k in dic.keys():
  dic[k].sort()
  ans += dic[k][0]
  rest.extend(dic[k][1:])
if N-1==M:
  print(0)
  exit()
if N<2*(N-M-1):
  print('Impossible')
  exit()

rest.sort()
remain = 2*(N-M-1)-len(dic.keys())
ans += sum(rest[:remain])
print(ans)
