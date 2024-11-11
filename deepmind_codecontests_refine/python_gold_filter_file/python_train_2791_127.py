N,K = map(int, input().split())
A = list(map(int, input().split()))

P = [1e9]*N
P[0] = 0

for i in range(1,N):
  for j in range(1,min(K+1,i+1)):
    P[i] = min(P[i], abs(A[i]-A[i-j])+P[i-j])
  
print(P[N-1])
