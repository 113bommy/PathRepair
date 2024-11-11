import itertools

n,m,r=map(int,input().split())
D=[[10**10]*n for _ in range(n)]
for i in range(n):
    D[i][i]=0
R=list(map(int,input().split()))
for i in range(m):
    a,b,c=map(int,input().split())
    D[a-1][b-1]=c
    D[b-1][a-1]=c

for k in range(n):
    for i in range(n):
        for j in range(n):
            D[i][j]=min(D[i][j],D[i][k]+D[k][j])

A=[]
for v in itertools.permutations(R,r):
    ans=0
    for i in range(r-1):
        ans+=D[v[i]-1][v[i+1]-1]
    A.append(ans)
print(min(A))