n=int(input())
g=[[]for i in range(n)]
for i in range(n-1):
    a,b=map(int,input().split())
    g[a-1].append((b-1,i))
    g[b-1].append((a-1,i))

def path(i,goal,mam=-1):
    if len(g[i][0])==1 and g[0]==mam:
        return 0
    else:
        for j,idx in g[i]:
            if j==mam:
                continue
            if j==goal:
                return 1<<idx
            p=path(j,goal,i)
            if p>0:
                return p | (1<<idx)
        return 0

m=int(input())
ps=[]
for _ in range(m):
    a,b=map(int,input().split())
    ps.append(path(a-1,b-1))

dp=[0]*(1<<m)
dp[0]=1
for i in range(n-1):
    newdp=[0]*(1<<m)
    hit=0
    for j,p in enumerate(ps):
        a=p & (1<<i)
        if p & (1<<i):
            hit+=1<<j
    for j in range(1<<m):
        newdp[j|hit]+=dp[j]
    for j in range(1<<m):
        dp[j]+=newdp[j]
print(dp[-1])