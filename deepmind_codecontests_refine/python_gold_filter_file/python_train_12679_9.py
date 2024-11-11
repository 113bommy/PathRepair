N,M,L=map(int,input().split())
G=[[10**15 for i in range(N)] for i in range(N)]
for i in range(M):
    a,b,c=map(int,input().split())
    G[a-1][b-1]=c
    G[b-1][a-1]=c
for k in range(N):
    for i in range(N):
        for j in range(N):
            G[i][j]=min(G[i][j],G[i][k]+G[k][j])
H=[[10**15 for i in range(N)] for i in range(N)]
for i in range(N):
    for j in range(N):
        if G[i][j]<=L:
            H[i][j]=1
for k in range(N):
    for i in range(N):
        for j in range(N):
            H[i][j]=min(H[i][j],H[i][k]+H[k][j])
Q=int(input())
for line in range(Q):
    s,t=map(int,input().split())
    s-=1;t-=1
    if H[s][t]==10**15:
        print(-1)
    else:
        print(H[s][t]-1)
