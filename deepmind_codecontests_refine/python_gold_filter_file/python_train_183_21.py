n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))
d=sum(B)
for i in range(n-1):
  if A[i+1]-A[i]==1:
    d+=C[A[i]-1]
print(d)