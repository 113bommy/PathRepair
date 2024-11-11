import math

N,K = map(int,input().split())
A = list(map(int,input().split()))
F = list(map(int,input().split()))
if sum(A) <= K:
  print(0)
  exit()
A.sort()
F.sort(reverse=True)

l,r = -1,10**12+1

while r-l > 1:
  m = (l+r)//2

  k = 0
  for i in range(N):
    a,f = A[i], F[i]
    k += max(0,a-(m//f))

  if k <= K:
    r = m
  else:
    l = m

print(r)