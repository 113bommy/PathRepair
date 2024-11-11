from heapq import heappush, heappop
X, Y, Z, K, *L = map(int, open(0).read().split())
A = L[:X]
B = L[X:X+Y]
C = L[X+Y:]
ab = []
for i in range(X):
  for j in range(Y):
    ab += [A[i]+B[j]]
ab.sort(reverse=True)
ls = []
for i in range(Z):
  heappush(ls,(-ab[0]-C[i],i,0))
for i in range(K):
  m, j, cnt = heappop(ls)
  print(-m)
  if cnt+1<X*Y:
    heappush(ls,(-ab[cnt+1]-C[j],j,cnt+1))