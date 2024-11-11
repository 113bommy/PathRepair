import sys,os,io
from collections import deque
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def bfs(curr):
    q = deque()
    dist = [-1]*n
    q.append(curr)
    dist[curr]=0
    while(q):
        curr = q.popleft()
        for i in graph[curr]:
            if dist[i]==-1:
                dist[i] = dist[curr]+1
                q.append(i)
    return dist

n,m,k = [int(i) for i in input().split()]
a = [int(i)-1 for i in input().split()]
graph = [[] for i in range (n)]
for i in range (m):
    ui,vi = [int(i)-1 for i in input().split()]
    graph[ui].append(vi)
    graph[vi].append(ui)
da = bfs(0)
db = bfs(n-1)
x = [da[i] for i in a]
y = [db[i] for i in a]
xy = [[x[i],y[i]] for i in range (k)]
xy.sort()
m = xy[0][0]
ans = 0
for i in range (1,k):
    ans = max(ans, m+xy[i][1]+1)
    m = max(m, xy[i][0])
ans = min(ans,da[-1])
print(ans)