n,c=map(int,input().split())
D=[[0]*c for i in range(c)]
for i in range(c):
  D[i]=list(map(int,input().split()))
C=[[0]*n for i in range(n)]
for i in range(n):
  C[i]=list(map(int,input().split()))
  for j in range(n):
    C[i][j]=C[i][j]-1
A=[[0]*c for i in range(3)]
for i in range(n):
  for j in range(n):
    A[(i+j)%3][C[i][j]]+=1
ans=0
e=10**20
for i in range(c):
  for j in range(c):
    if j==i:
      continue
    for k in range(c):
      if k==i:
        continue
      if k==j:
        continue
      f=0
      for u in range(c):
        f=f+A[0][u]*D[u][i]+A[1][u]*D[u][j]+A[2][u]*D[u][k]
      if e>f:
        e=f
print(e)