n,m=map(int,input().split())
vis=[0]*(n+1)
ans=0
l=[]
for i in range(m):
    l.append(list(map(int,input().split())))
l.sort(key=lambda i:i[2])
for j in range(m):
    for k in range(l[j][0],l[j][1]+1):
        if not vis[k]:
            vis[k]=1
            ans+=l[j][3]
print(ans)