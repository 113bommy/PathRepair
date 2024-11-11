n,m=map(int,input().split())
l=[]
for _ in range(n):
    t=list(map(int,input().split()))
    l.append(t)
adj=[]
for i in range(1+n+m):
    adj.append([])

for i in range(n):
    el=l[i]
    pl=i+1
    for a in range(1,el[0]+1):
        s=pl
        e=el[a]+n
        adj[s].append(e)
        adj[e].append(s)
visited=[0]*(1+n+m)
def bfs(node):
    if visited[node]:
        return
    visited[node]=1
    for i in adj[node]:
        bfs(i)
p=0
t=0

for i in range(1,1+n+m):
    if visited[i] == 0:
        if i > n and len(adj[i])== 0:
            pass
        elif i<=n and len(adj[i])==0:
            t+=1
        else:
            bfs(i)
            p+=1
print(max(p-1,0)+t)

