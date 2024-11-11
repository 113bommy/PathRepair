n,m,r=map(int,input().split())
root=list(map(int,input().split()))
abc=[list(map(int,input().split())) for _ in [0]*m]
inf=10**10
dist=[[inf for _ in [0]*n] for _ in [0]*n]
for i in range(n):dist[i][i]=0
for a,b,c in abc:
    dist[a-1][b-1]=c
    dist[b-1][a-1]=c
for k in range(n):
    for i in range(n):
        for j in range(n):dist[i][j]=min(dist[i][j],(dist[i][k]+dist[k][j]))

from itertools import permutations

p=list(permutations(root))

D=10**10
for i in p:
    d=0
    for j in range(len(i)-1):
        d+=dist[i[j]-1][i[j+1]-1]
    D=min(D,d)
print(D)