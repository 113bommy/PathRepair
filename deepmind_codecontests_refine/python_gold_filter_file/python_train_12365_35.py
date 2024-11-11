N,K=map(int,input().split())
A=list(map(int,input().split()))

for i in range(N-K):
  if A[K+i]>A[i]:
    print("Yes")
  else:
    print("No")