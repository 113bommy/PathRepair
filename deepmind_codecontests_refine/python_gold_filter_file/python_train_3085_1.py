# cook your dish here
n,m=map(int,input().split())
from collections import defaultdict 
ar=list(map(int,input().split()))
ax=defaultdict(list)
ans=0
for i in range(m):
    a,b=map(int,input().split())
    a=a-1 
    b=b-1
    ax[a].append(b)
    ax[b].append(a) 
if(m==0):
    print(sum(ar))
else:
    vis=[False]*n 
    for i in range(n):
        if(vis[i]==False):
            qu=[]
            qu.append(i)
            a=ar[i]
            while(qu):
                u=qu.pop(0)
                a=min(a,ar[u])
                vis[u]=True 
                for j in ax[u]:
                    if(vis[j]==False):
                        qu.append(j) 
            ans+=a 
    print(ans)
                
    