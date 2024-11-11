import sys
def inp():
    return sys.stdin.readline()
n=int(inp())
el=[]
deg=[0]*(n+1)
edge={}
ans_edge={}
for _ in range(n-1):
    u,v=map(int,inp().split())
    el.append((u,v))
    deg[u]+=1 
    deg[v]+=1
    if u not in edge:
        edge[u]=set()
    if v not in edge:
        edge[v]=set()
ll=[(min(deg[i[1]],deg[i[0]]),max(deg[i[1]],deg[i[0]]),i) for i in el]
ll.sort(reverse=True)
val=0
#print(ll)
while val<n-1:
    rmv=ll.pop()
    vtx=rmv[1]
    ans_edge[rmv[2]]=val 
    val+=1
    #del edge[vtx]
for i in el:
    print(ans_edge[i])
        
    