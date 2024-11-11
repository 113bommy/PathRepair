from heapq import heappush,heappop

N,M,S=map(int,input().split())
edges = [tuple(map(int,input().split())) for _ in range(M)]
cd = [tuple(map(int,input().split())) for _ in range(N)]
INF= 10**15
mod=55

mmax = sum([edges[i][2] for i in range(M)])
if S>mmax:
  S = mmax

G=[{} for _ in range((mmax+1)*mod+N+1)]
for i in range(M):
  u,v,a,b=edges[i]
  for p in range(a,mmax+1):
    G[u+p*mod][v+(p-a)*mod] = b
    G[v+p*mod][u+(p-a)*mod] = b
    
for i in range(N):
  c,d=cd[i]
  for p in range(mmax+1-c):
    G[i+1+p*mod][i+1+(p+c)*mod] = d
    
def dijkstra(start = 0):
    
    d = [INF for i in range(len(G)+1)]
    d[start] = 0
    
    que = []
    heappush(que, (0, start))

    while len(que):
        p = heappop(que)
        v = p[1]
        
        if d[v] < p[0]:
            continue
            
        for u in G[v].keys():
            if d[u] > d[v] + G[v][u]:
                d[u] = d[v] + G[v][u]
                heappush(que, (d[u], u))
    
    return d
  
start = 1+S*mod
d = dijkstra(start)

ans=[INF]*(N+1)
for i in range(2,len(G)+1):
  v = i%mod
  if v>N or v<2:continue
  ans[v] = min(ans[v],d[i])
  
print(*ans[2:])