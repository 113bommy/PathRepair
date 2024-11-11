import heapq as hq
n,m=map(int,input().split())
d={}
for i in range(m):
    x,y=map(int,input().split())
    if x not in d:
        d[x]=[]
    if y not in d:
        d[y]=[]
    d[x].append(y)
    d[y].append(x)
ans=[]
q=[1]
hq.heapify(q)
visit=(n+1)*[0]
visit[1]=1
while len(q)!=0:
    node=hq.heappop(q)
    ans.append(node)
    for i in d[node]:
        if visit[i]==0:
            hq.heappush(q,i)
            visit[i]=1

print(*ans)
