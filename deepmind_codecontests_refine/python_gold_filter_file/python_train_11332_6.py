n,m=map(int,input().split())
A=[input() for _ in range(n)]
B=[input() for _ in range(m)]
ok=0
for i in range(n-m+1):
  for k in range(n-m+1):
    if B[0]==A[i][k:k+m]:
      for j in range(i,i+m):
        if B[j-i]!=A[j][k:k+m]:
          break
      else:
        ok=1
print("Yes" if ok==1 else "No")