#入力高速化 + 再帰回数制限解除
import sys
input=sys.stdin.readline
sys.setrecursionlimit(10000000)
#ダイクストラ
#単一始点最短経路(正の辺のみ)
#s=始点 n=頂点数 edgeは隣接リスト(edge=[[[1,2],[2,4]],[[2,1]],[]])
#0-indexed
from heapq import heappop,heappush
def dijkstra(s,n,edge):
  inf=10**17
  ans=[inf]*n
  ans[s]=0
  h=[[0,s]]
  while h:
    c,v=heappop(h)
    if ans[v]<c:continue
    for u,t in edge[v]:
      if c+t<ans[u]:
        ans[u]=c+t
        heappush(h,[c+t,u])
  return ans
#solve
n,m,s,t=map(int,input().split())
s-=1
t-=1
yen_edge=[[]for _ in range(n)]
snuuk_edge=[[]for _ in range(n)]
for _ in range(m):
  u,v,a,b=map(int,input().split())
  u-=1
  v-=1
  yen_edge[u].append([v,a])
  yen_edge[v].append([u,a])
  snuuk_edge[u].append([v,b])
  snuuk_edge[v].append([u,b])
yen=dijkstra(s,n,yen_edge)
snuuk=dijkstra(t,n,snuuk_edge)
ans=[10**15-(yen[i]+snuuk[i])for i in range(n)]
for i in range(n-2,-1,-1):ans[i]=max(ans[i],ans[i+1])
for i in ans:print(i)
