N,K=map(int, input().split())
A=list(map(int, input().split()))

def f(A):
  D=[0]*(N+1)
  for j in range(N):
    mi=max(j-A[j],0)
    ma=min(j+A[j],N-1)
    D[mi]+=1
    D[ma+1]-=1   
  for i in range(1,N):
    D[i]+=D[i-1]
  A=D[:-1]
  return A 

for i in range(min(K,42)):
  A=f(A)
print(*A)