import itertools
inf=10**8
n,m,R=map(int,input().split())
r=list(map(int,input().split()))
d=[[inf]*n for i in range(n)]
for i in range(n):
    d[i][i]=0
ans=inf
for i in range(m):
    a,b,c=map(int,input().split())
    d[a-1][b-1]=c
    d[b-1][a-1]=c
for k in range(n):
    for i in range(n):
        for j in range(n):
            d[i][j]=min(d[i][j],d[i][k]+d[k][j])
for i in itertools.permutations(r):
    preans=0
    for j in range(R-1):
        preans+=d[i[j]-1][i[j+1]-1]
    ans=min(ans,preans)
print(ans)