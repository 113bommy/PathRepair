import sys
sys.setrecursionlimit(10**6)

n=int(input())
g=[set() for _ in range(n*(n-1)//2+1)]
visit=[0]*(n*(n-1)//2+1)
d=[0]*(n*(n-1)//2+1)

for i in range(1,n+1):
    last=0
    for j in list(map(int,input().split())):
        mi,ma=(min(i-1,j-1),max(i-1,j-1))
        current=ma*(ma-1)//2+mi+1
        g[last].add(current)
        last=current

def dfs(u):
    if visit[u]==2:
        return d[u]
    
    ans=0
    visit[u]=1
    for v in g[u]:
        if visit[v]==1:
            print(-1)
            exit(0)
        
        d[u]=max(d[u],1+dfs(v))
    
    visit[u]=2
    return d[u]

print(dfs(0))