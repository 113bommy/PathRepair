n,m,s = map(int,input().split())
road = [[] for _ in range(n)]
#print(road)
for _ in range(m):
  u,v,a,b = map(int,input().split())
  u -= 1
  v -= 1
  road[u].append([v,a,b])
  road[v].append([u,a,b])
#print(road)
coin = []
for _ in range(n):
  c,d = map(int,input().split())
  coin.append([c,d])
if s >= 2500:
  s = 2499
inf = 10**18
#print('#')
arr = [[inf for _ in range(2500)] for _ in range(n)]
c,d = coin[0]
#print(c,d)
#print(len(arr[0]))
for i in range(2500):
  if i <= s:
    arr[0][i] = 0
  elif i - c < 0:
    arr[0][i] = arr[0][0]+d
  else:
    arr[0][i] = arr[0][i-c]+d
now = {0}
#print(road)
for _ in range(50):
  #print(now)
  last = now
  now = set()
  for x in last:
    for y in road[x]:
      #print('#',x,y)
      v,a,b = y
      now.add(v)
      c,d = coin[v]
      for i in range(2500):
        if i + a < 2500:
          arr[v][i] = min(arr[v][i],arr[x][i+a]+b)
      for i in range(2500):
        if i - c < 0:
          arr[v][i] = min(arr[v][i],arr[v][0]+d)
        else:
          arr[v][i] = min(arr[v][i],arr[v][i-c]+d)
for ii in range(1,n):
  print(arr[ii][0])
#print(arr[0])