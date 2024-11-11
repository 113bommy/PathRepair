import sys

input=sys.stdin.readline
sys.setrecursionlimit(1000000)

N,M=map(int,input().split())
edge=[[] for i in range(0,N)]
dedge=[0 for i in range(0,N)]
data=[]
dic={}
for i in range(M):
    a,b=map(int,input().split())
    edge[a-1].append(b-1)
    edge[b-1].append(a-1)
    dedge[a-1]+=1
    dic[(a-1,b-1)]=0
    dic[(b-1,a-1)]=0
    dic[(a-1,b-1)]=i
    dic[(b-1,a-1)]=i
    data.append([a-1,b-1,0])

if M%2==1:
    print(-1)
    exit()

ans=[0 for i in range(N)]
treeedge=[[] for i in range(0,N)]
visit=set([0])
q=set([0])
sub=set([])
while q:
    while q:
        x=q.pop()
        for i in edge[x]:
            if i not in visit:
                treeedge[x].append(i)
                treeedge[i].append(x)
                visit.add(i)
                sub.add(i)

        if not q:
            q=sub
            sub=set([])
            break



def dfs(v,pv):
    if len(treeedge[v])==1 and v!=0:
        ans[v]=(dedge[v]%2,pv)
        return dedge[v]%2

    A=dedge[v]%2
    for i in treeedge[v]:
        if i!=pv:
            A+=dfs(i,v)
    ans[v]=(A%2,pv)
    return ans[v][0]

dfs(0,-1)

for i in range(1,N):
    val,parent=ans[i]
    if val==1:
        index=dic[(i,parent)]
        data[index][2]=1

for i in range(M):
    a,b,val=data[i]
    if val==0:
        print(a+1,b+1)
    else:
        print(b+1,a+1)
