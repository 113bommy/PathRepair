N,C=map(int,input().split())
D=[list(map(int,input().split())) for i in range(C)]
A=[list(map(int,input().split())) for i in range(N)]
X=[[0]*C for i in range(3)]
for c in range(C):
  for i in range(N):
    for j in range(N):
      X[(i+j)%3][c]+=D[A[i][j]-1][c]
P=10**20
for i in range(C):
  for j in range(C):
    for k in range(C):
      if len(set([i,j,k]))==3:
        P=min(P,X[0][i]+X[1][j]+X[2][k])
print(P)