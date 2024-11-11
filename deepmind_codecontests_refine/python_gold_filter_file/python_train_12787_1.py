import sys

input=sys.stdin.readline
sys.setrecursionlimit(10**7)

N=int(input())
edge=[[] for i in range(N)]
for i in range(N-1):
    a,b=map(int,input().split())
    edge[a].append(b)
    edge[b].append(a)

antena=[]
for i in range(N):
    if len(edge[i])>2:
        antena.append(i)

if not antena:
    print(1)
    exit()

parent=[-1]*N
root=antena[0]

def dfs(v,pv):
    parent[v]=pv
    for i in edge[v]:
        if i!=pv:
            dfs(i,v)

dfs(root,-1)

antena=set(antena)

q=[root]
sub=[]
while q:
    while q:
        x=q.pop()
        if x in antena:
            v=x
            while parent[v] not in antena and parent[v]!=-1:
                antena.add(parent[v])
                v=parent[v]
        for nv in edge[x]:
            if nv!=parent[x]:
                sub.append(nv)

        if not q:
            q=sub
            sub=[]
            break

ans=0
for u in antena:
    if len(edge[u])==1:
        ans+=1
    elif len(edge[u])==2:
        check=0
        for v in edge[u]:
            check+=(v in antena)
        if check==1:
            ans+=1
    else:
        check=0
        for v in edge[u]:
            check+=(v in antena)
        if check>=len(edge[u])-1:
            continue
        else:
            ans+=len(edge[u])-1-check
print(ans)
