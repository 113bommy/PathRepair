import sys
input = sys.stdin.readline
from collections import defaultdict
from math import inf
from heapq import heappop,heappush
def dijkstra(start):
    heap,dist=[(0,start)],[inf]*(n+1)
    dist[start]=0
    while heap:
            d,vertex=heappop(heap)
            for child,weight in graph[vertex]:
                    weight+=d
                    if dist[child]>weight:
                        dist[child]=weight
                        heappush(heap,(weight,child))
    return(dist)


n,m,k=map(int,input().split())
graph = [[] for _ in range(n + 1)]
weights=defaultdict(int)
connectlist=[]
for i in range(m):
    a,b,w=map(int,input().split())
    graph[a].append((b,w))
    graph[b].append((a,w))
    connectlist.append((a,b))
route=[]
distlist=[]
for i in range(n):
    distlist.append(dijkstra(i+1))
for i in range(k):
    src,dst=map(int,input().split())
    route.append((src,dst))
    
ans=10**10
for i in connectlist:
    tmp=0
    for j in route:
        tmp+=min(distlist[j[0]-1][j[1]],distlist[j[0]-1][i[0]]+distlist[j[1]-1][i[1]],distlist[j[0]-1][i[1]]+distlist[j[1]-1][i[0]])
    if tmp<ans:
        ans=tmp
print(ans)
        
                
                            
        
                
            
                
        
            
            
            
        
