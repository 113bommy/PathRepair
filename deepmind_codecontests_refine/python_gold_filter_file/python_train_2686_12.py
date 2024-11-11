import sys
input = sys.stdin.readline
p=int(input())
A=[int(i) for i in input().split()]
mod=p
B=[0]*p
for i in range(p):
  C=[1]*p
  B[0]=(B[0]-A[i])%mod
  for j in range(1,p):
    C[j]=(C[j-1]*i)%mod
    B[j]=(B[j]-A[i]*C[j])%mod
    if j==p-1:
      B[j]=(B[j]+A[i])%mod
B=B[::-1]
print(*B)
    
