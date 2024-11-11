h,w=map(int,input().split())
A=[[0]*w for i in range(h)]
for i in range(h):
  A[i]=list(map(int,input().split()))
B=[[0]*w for i in range(h)]
for i in range(h):
  B[i]=list(map(int,input().split()))
C=[[0]* w for i in range(h)]
for i in range(h):
  for j in range(w):
    C[i][j]=abs(A[i][j]-B[i][j])
dp=[[[0]*6401 for j in range(h+1)] for i in range(h+w+1)]
dp[0][0][C[0][0]]=1
for i in range(h+w):
  for j in range(max(0,i-w),min(i,h)+1):
    for k in range(6401):
      if dp[i][j][k]==1:
        if i-j<w-1:
          if k+C[j][i-j+1]<6400:
            dp[i+1][j][k+C[j][i-j+1]]=1
          dp[i+1][j][abs(k-C[j][i-j+1])]=1
        if j<h-1:
          if k+C[j+1][i-j]<6400:
            dp[i+1][j+1][k+C[j+1][i-j]]=1
          dp[i+1][j+1][abs(k-C[j+1][i-j])]=1
for k in range(6400):
  if dp[h+w-2][h-1][k]==1:
    print(k)
    exit()