n,m,l=map(int,input().split())
A=[list(map(int,input().split())) for i in range(n)]
B=[list(map(int,input().split())) for i in range(m)]
#print(A)
#print(B)

for i in range(n):
  for j in range(l):
    youso=0
    for k in range(m):
      youso+=A[i][k]*B[k][j]
    if j==0:
      print(youso,end="")
    else:
      print("",youso,end="")
  print("")
