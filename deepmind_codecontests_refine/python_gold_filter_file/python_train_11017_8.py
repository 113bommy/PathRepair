N = int(input())
A = list(map(int,input().split()))
maxa = max(A)
mina = min(A)
print(2*N-1)
if abs(maxa) > abs(mina):
  k = A.index(maxa)
  for i in range(N):
    print(k+1,i+1)
    A[i] += A[k]
  for i in range(1,N):
    A[i] += A[i-1]
    print(i,i+1)
else:
  k = A.index(mina)
  for i in range(N):
    print(k+1,i+1)
    A[i] += A[k]
  for i in range(N,1,-1):
    print(i,i-1)
    A[i-2] += A[i-1]

