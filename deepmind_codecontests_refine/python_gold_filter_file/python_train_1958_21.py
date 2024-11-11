from collections import deque,defaultdict
import sys
sys.setrecursionlimit(10**7)
N,Q=map(int,input().split())
table=[[] for i in range(N)]
ddcost=defaultdict(tuple)
for i in range(N-1):
    a,b,c,d=map(int,input().split())
    a,b,c=a-1,b-1,c-1
    table[a].append(b)
    table[b].append(a)
    ddcost[(min(a,b),max(b,a))]=(c,d)
#print(table)
#print(ddcost)
H=deque()
H.append(0)
visit=[-1]*N
visit[0]=0
parent=[[-1]*N for i in range(18)]
while H:
    x=H.popleft()
    for y in table[x]:
        if visit[y]!=-1:
            continue
        parent[0][y]=x
        visit[y]=visit[x]+1
        H.append(y)
for k in range(17):
    for i in range(N):
        if parent[k][i]<0:
            parent[k+1][i]=-1
        else:
            parent[k + 1][i]=parent[k][parent[k][i]]
def lca(u,v):
    if visit[u]>visit[v]:
        u,v=v,u
    for k in range(18):
        if ((visit[v]-visit[u] )>>k)&1:
            v=parent[k][v]
    if u==v:
        return u
    for k in range(17,-1,-1):
        if parent[k][u]!=parent[k][v]:
            u=parent[k][u]
            v=parent[k][v]
    return parent[0][u]

query=[]
sakidori=[set() for i in range(N)]
for i in range(Q):
    x,y,u,v=map(int,input().split())
    x,u,v=x-1,u-1,v-1
    if u>=v:
        u,v=v,u
    pa=lca(u,v)
    sakidori[u].add(x)
    sakidori[v].add(x)
    sakidori[pa].add(x)
    query.append((x,y,u,v,pa))
ddcolorsum=defaultdict(int)
ddcolornum=defaultdict(int)
W=deque()
colorsum=[0]*(N)
colornum=[0]*(N)
dist=[0]*N
vi=[0]*N
W.append((0,0,1))

while W:
    #print(W)
    pa,ci,vector=W.pop()
    if vector==-1:
        color,dis=ddcost[(min(pa,ci),max(pa,ci))]
        colorsum[color]-=dis
        colornum[color]-=1
        #print(colorsum, colornum, pa, ci, vector)
        continue
    if pa==0 and ci==0:
        for y in table[ci]:
            W.append((ci, y, 1))
        for co in sakidori[0]:
            ddcolorsum[(0,co)]=0
            ddcolornum[(0,co)]=0
        continue
    color,dis=ddcost[(min(pa,ci),max(pa,ci))]
    dist[ci]=dist[pa]+dis
    colorsum[color]+=dis
    colornum[color]+=1
    for co in sakidori[ci]:
        ddcolorsum[(ci, co)] = colorsum[co]
        ddcolornum[(ci, co)] = colornum[co]
    #print(colorsum,colornum,pa,ci,vector)
    W.append((pa,ci,-1))
    for y in table[ci]:
        if y==pa:
            continue
        W.append((ci,y,1))
#print(ddcolorsum)
#print(ddcolornum)
#print(dist)
def dista(x,y,u):
    return dist[u]-ddcolorsum[(u,x)]+y*ddcolornum[(u,x)]
for x,y,u,v,pa in query:
    #print(x,y,u,v,pa)
    #print(dista(x,y,u),dista(x,y,v),dista(x,y,pa))
    print(dista(x,y,u)+dista(x,y,v)-2*dista(x,y,pa))