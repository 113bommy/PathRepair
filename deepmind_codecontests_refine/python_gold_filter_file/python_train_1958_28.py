import sys

input=sys.stdin.readline
sys.setrecursionlimit(10**7)

N,Q=map(int,input().split())
edge=[[] for i in range(N)]
for i in range(N-1):
    a,b,c,d=map(int,input().split())
    edge[a-1].append((b-1,c,d))
    edge[b-1].append((a-1,c,d))

prv=[-1]*N
depth=[0]*N
dist=[0 for i in range(N)]
def dfs(v,pv):
    prv[v]=pv
    for nv,color,weight in edge[v]:
        if nv!=pv:
            depth[nv]=depth[v]+1
            dist[nv]=dist[v]+weight
            dfs(nv,v)

dfs(0,-1)

LV = (N-1).bit_length()
def construct(prv):
    kprv = [prv]
    S = prv
    for k in range(LV):
        T = [0]*N
        for i in range(N):
            if S[i] is None:
                continue
            T[i] = S[S[i]]
        kprv.append(T)
        S = T
    return kprv

kprv=construct(prv)

def lca(u, v):
    dd = depth[v] - depth[u]
    if dd < 0:
        u, v = v, u
        dd = -dd

    # assert depth[u] <= depth[v]
    for k in range(LV+1):
        if dd & 1:
            v = kprv[k][v]
        dd >>= 1

    # assert depth[u] == depth[v]
    if u == v:
        return u

    for k in range(LV-1, -1, -1):
        pu = kprv[k][u]; pv = kprv[k][v]
        if pu != pv:
            u = pu; v = pv

    # assert kprv[0][u] == kprv[0][v]
    return kprv[0][u]

query=[]
q=[[] for i in range(N)]
data={}
for i in range(Q):
    x,y,u,v=map(int,input().split())
    LCA=lca(u-1,v-1)
    query.append((x,y,u-1,v-1,LCA))
    q[u-1].append(x)
    q[v-1].append(x)
    q[LCA].append(x)

num=[0 for i in range(N)]
cdist=[0 for i in range(N)]

def dfsc(v,pv,color,weight):
    pn=num[color]
    num[color]+=1
    pd=cdist[color]
    cdist[color]+=weight
    for x in q[v]:
        data[(v,x)]=(0,0)
        data[(v,x)]=(num[x],cdist[x])

    for nv,ncolor,nweight in edge[v]:
        if nv!=pv:
            dfsc(nv,v,ncolor,nweight)

    num[color]=pn
    cdist[color]=pd



dfsc(0,0,0,0)

for x,y,u,v,LCA in query:
    d1=dist[LCA]-data[(LCA,x)][1]+data[(LCA,x)][0]*y
    d2=dist[u]-data[(u,x)][1]+data[(u,x)][0]*y
    d3=dist[v]-data[(v,x)][1]+data[(v,x)][0]*y
    print(d2-d1+d3-d1)