N,K=map(int,input().split())
A=[list(map(int,input().split())) for i in range(N)]
V=2*N+2
INF=10**14
G=[[] for i in range(V)]
D=[INF]*V
PV,PE=[0]*V,[0]*V
def ae(fr,to,ca,co):
  global G
  G[fr].append([to,ca,co,len(G[to]),0])
  G[to].append([fr,0,-co,len(G[fr])-1,0])

def mcf(s,t,f):
  global G,V,INF,D,PV,PE
  for i in range(V):
    for j in range(len(G[i])):
      G[i][j][4]=0
  r=0
  z=f
  while z>0:
    D=[INF]*V
    D[s]=0
    ud=True
    while ud:
      ud=False
      for x in range(V):
        if D[x]==INF:
          continue
        for i in range(len(G[x])):
          if G[x][i][1]>0 and D[G[x][i][0]]>D[x]+G[x][i][2]:
            D[G[x][i][0]]=D[x]+G[x][i][2]
            PV[G[x][i][0]]=x
            PE[G[x][i][0]]=i
            ud=True
    if D[t]==INF:
      return -INF
    d=z
    x=t
    while x!=s:
      d=min(d,G[PV[x]][PE[x]][1])
      x=PV[x]
    z-=d
    r+=d*D[t]
    x=t
    while x!=s:
      G[PV[x]][PE[x]][1]-=d
      G[PV[x]][PE[x]][4]+=d
      G[x][G[PV[x]][PE[x]][3]][1]+=d
      G[x][G[PV[x]][PE[x]][3]][4]-=d
      x=PV[x]
  return r

s=N*2
t=s+1
for i in range(N):
  ae(s,i,K,0)
  ae(N+i,t,K,0)
  for j in range(N):
    ae(i,N+j,1,10**10-A[i][j])
ae(s,t,N*K,10**10)
print(N*K*10**10-mcf(s,t,N*K))
P=[['.']*N for i in range(N)]
for i in range(N):
  for j in range(len(G[i])):
    if G[i][j][4]>0:
      P[i][G[i][j][0]-N]='X'
  print(''.join(P[i]))