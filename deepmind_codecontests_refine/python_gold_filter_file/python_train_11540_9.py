from collections import deque
n,m=map(int,input().split())
A=[[0]*2 for i in range(m)]
for i in range(m):
  A[i]=list(map(int,input().split()))
ans=0
for i in range(m):
  B=[[] for i in range(n)]
  for j in range(m):
    if j==i:
      continue
    B[A[j][0]-1].append(A[j][1]-1)
    B[A[j][1]-1].append(A[j][0]-1)
  C=[0]*n
  C[0]=1
  D=deque([0])
  while len(D)>0:
    x=D[0]
    D.popleft()
    for j in range(len(B[x])):
      if C[B[x][j]]==0:
        D.append(B[x][j])
        C[B[x][j]]=1
  if C!=[1]*n:
    ans=ans+1
print(ans)