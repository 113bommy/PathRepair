from fractions import gcd

N,K = map(int,input().split())
A = list(map(int,input().split()))

if K > max(A):
  print('IMPOSSIBLE')
  exit()

d = A[0]
for a in A:
  d = gcd(d,a)

if K % d == 0:
  print('POSSIBLE')
else:
  print('IMPOSSIBLE')