N,M=map(int,input().split())
A=list(map(int,input().split()))
for i in range(M,N):
  if A[i]>A[i-M]:
    print("Yes")
  else:
    print("No")