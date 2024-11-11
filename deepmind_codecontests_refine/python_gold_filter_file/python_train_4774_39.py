n,ma,mb=map(int,input().split())
A=[]
for i in range(n):
  a,b,c=map(int,input().split())
  A.append([a,b,c])
DP=[[[float("inf")]*(10*n+1) for _ in range(10*n+1)] for _ in range(n+1)]
DP[0][0][0]=0
for i in range(n):
  a,b,c=A[i][0],A[i][1],A[i][2]
  for j in range(10*(i+1)+1):
    for k in range(10*(i+1)+1):
      if j>=a and k>=b:
        DP[i+1][j][k]=min(DP[i][j-a][k-b]+c,DP[i][j][k])
      else:
        DP[i+1][j][k]=DP[i][j][k]
ans=float("inf")
for i in range(10*n+1):
  for j in range(10*n+1):
    if i*mb==j*ma and i*j!=0:
      ans=min(ans,DP[n][i][j])
print(ans if ans!=float("inf") else -1)