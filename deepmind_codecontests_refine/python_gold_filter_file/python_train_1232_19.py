n=int(input())
G=[[] for i in range(n)]
for i in range(n-1):
    a,b,c=map(int,input().split())
    G[a-1].append((b-1,c))
    G[b-1].append((a-1,c))
q,k=map(int,input().split())
k=k-1
stack=[k]
dis=[-1]*n
dis[k]=0
while stack!=[]:
    now=stack.pop()
    d=dis[now]
    for i in G[now]:
        if dis[i[0]]==-1:
            dis[i[0]]=d+i[1]
            stack.append(i[0])
for i in range(q):
    x,y=map(int,input().split())
    x=x-1
    y=y-1
    print(dis[x]+dis[y])

