N,M=map(int,input().split())
INF = 10**5
D=[[INF]*N for _ in range(N)]
for i in range(N):
  D[i][i]=0
path=[]
for i in range(M):
  a,b,c = map(int,input().split())
  D[a-1][b-1]=c
  D[b-1][a-1]=c
  path.append([a-1,b-1,c])
for k in range(N):
  for i in range(N-1):
    for j in range(i+1,N):
      D[i][j]=min(D[i][j],D[i][k]+D[j][k])
      D[j][i]=D[i][j]
ans=0
for a,b,c in path:
  if D[a][b]<c:
    ans+=1
print(ans)
