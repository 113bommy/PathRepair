def bfs(beg,deeps,d):
    levels=[beg]
    while levels:
        cur=levels.pop()
        for x in d[cur]:
            if deeps[x]==0:
                deeps[x]=deeps[cur]+1
                levels.insert(0,x)
    deeps[beg]=0
    return

n,m,s,t=map(int,input().split())

d=[[] for i in range(n+1)]

for i in range(m):
    x,y=map(int,input().split())
    d[x].append(y)
    d[y].append(x)

froms=[0 for i in range(n+1)]
fromt=[0 for i in range(n+1)]

bfs(s,froms,d)
bfs(t,fromt,d)

ans=0
for i in range(1,n+1):
    for j in range(i+1,n+1):
        ij=min(froms[i]+fromt[j]+1,froms[j]+fromt[i]+1)
        if ij>=froms[t]: ans+=1
print(ans-m)
