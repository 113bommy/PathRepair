import sys
sys.setrecursionlimit(1000000)
n,m = map(int,input().split())
a = [0]*m
b = [0]*m
for i in range(m):
  u,v = map(int, input().split())
  a[i] = u-1
  b[i] = v-1
par = [i for i in range(n)]
size = [1]*n
incomb = [n*(n-1)//2]*m

def root(x):
  if par[x] == x: 
    return x
  else:
    par[x] = root(par[x])
    return par[x]
    
def isSame(x,y):
  return par[x] == par[y]

def union(x,y):
  x = root(x)
  y = root(y)
  if x == y:
    return
  else:
    par[y] = x
    size[x] += size[y]
    
def size_count(x):
  return size[root(x)]

for i in reversed(range(1,m)):
  q_a = a[i]
  q_b = b[i]
  size_a = size_count(q_a)
  size_b = size_count(q_b)
  if not isSame(q_a,q_b):
    union(q_a,q_b)
    incomb[i-1] = incomb[i] - size_a*size_b
  else:
    incomb[i-1] = incomb[i]

for i in incomb:
  print(i)