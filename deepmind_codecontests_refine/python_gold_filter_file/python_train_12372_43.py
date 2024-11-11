N=int(input())
A=[list(map(int,input().split())) for _ in range(N)]

e=[[True]*N for _ in range(N)]
ans=0
for k in range(N):
  for i in range(N):
    for j in range(N):
      if A[i][j] > A[i][k] + A[k][j]:
        print(-1)
        exit()
      elif (A[i][j]==A[i][k]+A[k][j]) and (A[i][k]!= 0) and (A[k][j]!= 0):
        e[i][j]=False

ans=0
for i in range(N):
  for j in range(N):
    if e[i][j]: ans+=A[i][j]

print(ans//2)