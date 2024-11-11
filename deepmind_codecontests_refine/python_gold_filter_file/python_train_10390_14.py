mi = lambda: map(int, input().split())
e = enumerate
n,k = mi()
m = (n+k).bit_length()
a = list(mi())
g = [None]*n

d = dict()
for i,x in e(a):
  d[x] = i
for i,x in e(a):
  g[d[x]] = ((i+1)%n,int(d[x]>=i)+int(i+1==n))
  d[x] = i
db = [g]
for _ in range(m):
  old = db[-1]
  new = [None]*n
  for i in range(n):
    p,q = old[i]
    r,s = old[p]
    new[i] = (r,q+s)
  db.append(new)
cur = 0
st = m
cs = 0
while st>=0:
  p,q = db[st][cur]
  if cs+q < k:
    cs += q
    cur = p
  else:
    st -= 1
    
q = list()
while cur < n:
  if g[cur][1] == 0:
    cur = g[cur][0]
  elif g[cur] == (0,1):
    break
  else:
    q.append(a[cur])
    cur += 1
  
print(' '.join(map(str,q)))