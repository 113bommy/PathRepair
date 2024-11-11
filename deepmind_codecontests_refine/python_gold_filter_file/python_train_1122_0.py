M=10**9+7;n,k,*A=map(int,open(0).read().split());C=[[0]*(n+1)for _ in"_"*(n+1)]
for i in range(n+1):
 for j in range(i+1):C[i][j]=(1,C[i-1][j-1]+C[i-1][j])[j>0]%M
F=[[0]*(n+1)for _ in"_"*(k+1)];F[0][0]=1
for i in range(k):
 for j in range(n+1):
  for m in range(j+1):F[i+1][j]+=C[j][m]*F[i][m]*C[n-j+m][A[i]-j+m]
print(F[k][n]%M)