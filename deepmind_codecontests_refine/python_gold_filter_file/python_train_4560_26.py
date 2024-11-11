N, K = map(int, input().split())
A = [int(c) for c in input().split()]
F = [int(c) for c in input().split()]
A.sort()
F.sort(reverse=True)
M = 0
for i in range(N):
  if A[i]*F[i]>M:
    M = A[i]*F[i]

l = -1
r = M+1
while l+1<r:
  s = (l+r)//2
  cnt = 0
  for i in range(N):
    b = s//F[i]
    cnt += max(0, A[i]-b)
  if cnt>K:
    l = s
  else:
    r = s

print(r)
