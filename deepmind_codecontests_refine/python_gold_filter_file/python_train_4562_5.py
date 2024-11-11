from bisect import bisect_left
N,Q,*L = map(int, open(0).read().split())
A = L[:N]
S = []
M = []
x = 0
y = 0
m = sum(A)
for i in range(N):
  if i%2==0:
    x += A[i]
    S.append(x)
  else:
    y += A[i]
    S.append(y)
for i in range(N):
  M.append(m)
  m -= A[i]

for q in L[N:]:
  i = bisect_left(A,q)
  if 0<i<N and q-A[i-1]<=A[i]-q:
    i = i-1
  if i>=N-1:
    print(S[N-1])
    continue
  l = -1
  r = N
  while l+1<r:
    s = (l+r)//2
    k = N-1-s
    if s<=i:
      l = s
      continue
    x = s-i+1
    if x>k:
      r = s
      continue
    y = k-x
    m = i-y-1
    if m<0:
      l = s
      continue
    if q-A[m]<=A[s]-q:
      r = s
    else:
      l = s
  a = M[r]
  cnt = N-r
  cnt -= r-i-1
  b = i-cnt
  if b>=0:
    a += S[b]
  print(a)