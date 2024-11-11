from collections import defaultdict 
d=defaultdict(list)
n,m=map(int,input().split())
for i in range(m):
    a,b=map(int,input().split())
    a-=1 
    b-=1 
    d[a].append(b)
    d[b].append(a)
vis=[0]*n 
q=[0] 
vis[0]=1 
while q:
    t=q.pop(0)
    for i in d[t]:
        if not vis[i]:
            vis[i]=1 
            q.append(i)
if sum(vis)==n and m==n:
    print('FHTAGN!')
else:
    print('NO')