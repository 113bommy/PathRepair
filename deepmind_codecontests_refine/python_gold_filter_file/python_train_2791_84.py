def solve():
  n,k=map(int,input().split())
  H=list(map(int,input().split()))
  A=[0]*n
  for i in range(1,n):
    A[i]=min(A[i-j]+abs(H[i]-H[i-j]) for j in range(1,min(i+1,k+1)))
  return A[n-1]
print(solve())
