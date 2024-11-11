import sys
input = sys.stdin.readline
import heapq as hq
n,m = map(int,input().split())
s,t = map(int,input().split())
abd = [list(map(int,input().split())) for i in range(m)]
mod = 10**9+7
graph = [[] for i in range(n+1)]
for a,b,d in abd:
  graph[a].append((b,d))
  graph[b].append((a,d))
dists = [[10**18,0] for i in range(n+1)]
distt = [[10**18,0] for i in range(n+1)]
for start,dist in (s,dists),(t,distt):
  dist[start] = [0,1]
  q = [(0,start)]
  hq.heapify(q)
  while q:
    dx,x = hq.heappop(q)
    k = dist[x][1]
    for y,d in graph[x]:
      if dist[y][0] > dx+d:
        dist[y][0] = dx+d
        dist[y][1] = k
        hq.heappush(q,(dist[y][0],y))
      elif dist[y][0] == dx+d:
        dist[y][1] = (dist[y][1]+k)%mod
dst = dists[t][0]
ansls = []
for u,v,d in abd:
  for a,b in (u,v),(v,u):
    if dists[a][0] < distt[a][0]:
      if dists[a][0]*2 < dst and distt[b][0]*2 < dst:
        if dists[a][0]+distt[b][0]+d == dst:
          ansls.append(dists[a][1]*distt[b][1]%mod)
for v in range(1,n+1):
  if dists[v][0]*2 == distt[v][0]*2 == dst:
    ansls.append(dists[v][1]*distt[v][1]%mod)
sm = sum(ansls)%mod
ans = sm**2%mod
for i in ansls:
  ans = (ans-i**2)%mod
print(ans)