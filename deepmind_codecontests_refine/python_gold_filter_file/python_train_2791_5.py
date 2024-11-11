N,K = map(int,input().split())
H = list(map(int,input().split()))

A = [0]*N

for i in range(1,N):
  A[i] = min([(A[i-j]+abs(H[i]-H[i-j])) for j in range(1,min(K+1,i+1))])

print(A[N-1])
